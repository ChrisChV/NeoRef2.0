#ifndef MOD_DOM_H
#define MOD_DOM_H

#include <iostream>
#include "connector.h"
#include <fstream>
#include "Referido.h"
#include <vector>
#include <list>
#include <tuple>

using namespace std;

typedef tuple<ID,int,string> RefDTO;

int obtenerNivelReferido(SemanaBin semanaBin){
	int res = 0;
	for(auto iter = semanaBin.begin(); iter != semanaBin.end(); ++iter) if(*iter == '1') res++;
	return res;
}

void generarLista(){
	string file = "reporte.tex";
	ofstream ltx(file.c_str());
	if(ltx.fail()){
		string e = "Hubo un error en el archvo de reporte";
		throw(e);
	}
	ltx<<"\\documentclass[a4paper,12pt]{article}"<<endl;
    ltx<<"\\usepackage[utf8]{inputenc}"<<endl;
    ltx<<"\\usepackage[spanish]{babel}"<<endl;
    ltx<<"\\usepackage{epstopdf}"<<endl;
    ltx<<"\\begin{document}"<<endl; 	
 	MYSQL * connect = getConnect();
 	MYSQL_RES *res_set;
	MYSQL_ROW row;
	mysql_query(connect,"select * from Referidos;");
	res_set = mysql_store_result(connect);
	unsigned int numrows = mysql_num_rows(res_set);
	vector<list<RefDTO>> hash(8);
	for(int i = 0; i < numrows; i++){
		row = mysql_fetch_row(res_set);
		string semanaBin(row[2]);
		int nivel = obtenerNivelReferido(semanaBin);
		string msg = "Desaprobado";
		if(nivel >= 3) msg = "Aprobado";
		hash[nivel].push_back(make_tuple(row[0],nivel,msg));
	}
	ltx<<"\\begin{tabular}{l l l}"<<endl;
	ltx<<"Referido & Nivel & Estado \\\\"<<endl;
	for(int i = 0; i <= 7; i++){
		if(!hash[i].empty()){
			for(auto iter = hash[i].begin(); iter != hash[i].end(); ++iter){
				ltx<<get<0>(*iter)<<" & "<<get<1>(*iter)<<" & "<<get<2>(*iter)<<" \\\\"<<endl;
			}
		}
	}
	ltx<<"\\end{tabular}"<<endl;
    ltx<<"\\end{document}"<<endl;
    ltx.close();
    system("pdflatex reporte.tex");
    mysql_close(connect);
}

#endif