#include <iostream>
#include "connector.h"
#include "mod_readfile.h"
#include "RefTime.h"

using namespace std;



void ProcesarClick(string Dia_de_Comparacion, string file){
	try{
		RefDate today = getActualTime();
		int d = 0;
		if(Dia_de_Comparacion == "ayer") d = 1;
		else if(Dia_de_Comparacion != "hoy"){
			string e = "El dia de comparacion sólo puede ser ayer o hoy";
			throw(e);
		}
		vector<Referidos> ref = allRef(file);
		MYSQL * connect = getConnect();
		MYSQL_RES * res_set;
		MYSQL_ROW row;
		for(Referidos r : ref){
			if(today - d == r.lastClick){
				string query = "select SemanaBin from Referidos where idReferidos = " + r.idRef;
				mysql_query(connect,query.c_str());
				res_set = mysql_store_result(connect);
			}
		}
	}
}

