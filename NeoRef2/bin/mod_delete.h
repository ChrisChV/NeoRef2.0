#ifndef MOD_DELETE_H
#define MOD_DELETE_H

#include <iostream>
#include "RefTime.h"
#include "connector.h"

using namespace std;

void deleteGrupoRef(){
	RefDate today = getActualTime();
	MYSQL * connect  = getConnect();
	MYSQL_RES * res_set;
	MYSQL_ROW row;
	string query = "select idGrupoRef from GrupoRef where FechaFin < " + today + ";";
	mysql_query(connect,query.c_str());
	res_set = mysql_store_result(connect);
	unsigned int numrows = mysql_num_rows(res_set);
	if(numrows > 0){
		row = mysql_fetch_row(res_set);
		string query2 "delete from Referidos where idGrupoRef = '" + row[0] + "';";
		mysql_query(connect,query2.c_str());
	}

}

#endif