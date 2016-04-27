#ifndef MOD_DIARIO_H
#define MOD_DIARIO_H

#include <iostream>
#include "connector.h"
#include "mod_readFile.h"
#include "RefTime.h"

using namespace std;

void ProcesarClick(string Dia_de_Comparacion, string file){
	RefDate today = getActualTime();
	int d = 0;
	if(Dia_de_Comparacion == "ayer") d = 1;
	else if(Dia_de_Comparacion != "hoy"){
		string e = "El dia de comparacion sólo puede ser ayer o hoy";
		throw(e);
	}
	vector<Referido> ref = allRef(file);
	MYSQL * connect = getConnect();
	MYSQL_RES * res_set;
	MYSQL_ROW row;
	int i = 0;
	for(Referido r : ref){
		if(today - d == r.lastClick){
			i++;
			string query = "select SemanaBin from Referidos where idReferidos = '" + r.idRef + "';";
			mysql_query(connect,query.c_str());
			res_set = mysql_store_result(connect);
			row = mysql_fetch_row(res_set);
			SemanaBin semTemp = row[0];
			Day d = getDay(today);
			semTemp[d] = '1';
			string query2 = "update Referidos set SemanaBin = '" + semTemp + "' where idReferidos = '" + r.idRef + "';";
			mysql_query(connect,query2.c_str());
			string query3 = "update Referidos set Cliks = Cliks + 4 where idReferidos = '" + r.idRef + "';";
			mysql_query(connect,query3.c_str());
		}
	}
	mysql_close(connect);
	cout<<"Referidos activos->"<<i<<endl;
	cout<<"Total->"<<i*20<<endl;
}

#endif