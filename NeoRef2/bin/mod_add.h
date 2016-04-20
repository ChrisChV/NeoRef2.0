#include <iostream>
#include "mod_readfile.h"
#include "connector.h"
#include "RefTime.h"

using namespace std;

void add_all(string file){
	vector<Referido> vec = allRef(file);
	MYSQL * connect  = getConnect();
	MYSQL_RES * res_set;
	MYSQL_ROW row;
	for(Referido r : vec){
		string query = "select idGrupoRef from GrupoRef where FechaIni = " + r.fechaIni + ";";
		mysql_query(connect,query.c_str());
		res_set = mysql_store_result(connect);
		unsigned int rows = mysql_num_rows(res_set);
		if(rows == 0){
			RefDate date = r.fechaIni
			int day = date % 100;
			date = date / 100;
			int mes = date % 100;
			int year = date / 100;

			int diasMes = getDiasMes(mes, year);
			int day = day + 30;
			if(day > diasMes){
				day = day % diasMes;
				mes++;
				if(mes > 12){
					mes = mes % 12;
					year++;
				}
			}

			RefDate fechafin = (year * 10000) + (mes * 100) + day;
			string query2 = "insert into GrupoRef(FechaIni,FechaFin) values (" + r.fechaIni + "," + fechafin + ");";
			mysql_query(connect,query2.c_str());
			string query3 = "select idGrupoRef from GrupoRef order by idGrupoRef desc limit 1;";
			mysql_query(connect,query3.c_str());
			res_set = mysql_store_result(connect);
			row = mysql_fetch_row(res_set);
			string query4 = "insert into Referido values (" + r.idRef + ",0,0000000," + row[0] + ");";
			mysql_query(connect,query4.c_str());
		}
		else{
			string query5= "insert into Referido values (" + r.idRef + ",0,0000000," + row[0] + ");";
			mysql_query(connect,query5.c_str());
		}
	}
	mysql_close(connect);
}

void add_new(string file){
	vector<Referido> vec = allRef(file);
	MYSQL * connect  = getConnect();
	MYSQL_RES * res_set;
	MYSQL_ROW row;
	RefDate today = getActualTime();
	RefDate fechafin = 0;
	for(Referido r : vec){
		if(today == r.fechaIni){
			if(fechafin == 0){
				RefDate date = today;
				int day = date % 100;
				date = date / 100;
				int mes = date % 100;
				int year = date / 100;

				int diasMes = getDiasMes(mes, year);
				int day = day + 30;
				if(day > diasMes){
					day = day % diasMes;
					mes++;
					if(mes > 12){
						mes = mes % 12;
						year++;
					}
				}

				fechafin = (year * 10000) + (mes * 100) + day;
			}
			string query2 = "insert into GrupoRef(FechaIni,FechaFin) values (" + r.fechaIni + "," + fechafin + ");";
			mysql_query(connect,query2.c_str());
			string query3 = "select idGrupoRef from GrupoRef order by idGrupoRef desc limit 1;";
			mysql_query(connect,query3.c_str());
			res_set = mysql_store_result(connect);
			row = mysql_fetch_row(res_set);
			string query4 = "insert into Referido values (" + r.idRef + ",0,0000000," + row[0] + ");";
			mysql_query(connect,query4.c_str());
			
		}
	}
	mysql_close(connect);
}