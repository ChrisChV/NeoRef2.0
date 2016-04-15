#include <iostream>
#include <stdio.h>
#include <mysql.h>

using namespace std;

int main(){
	MYSQL * connect;
	connect = mysql_init(NULL);
	if(!connect){
		cout<<"EROORR"<<endl;
		return 1;
	}
	connect = mysql_real_connect(connect, "localhost", "root", "root", "test", 0,NULL,0);
	if(connect) cout<<"Yeeeeeeeeee"<<endl;
	else cout<<"NOOOOOOOOOOOOOOO"<<endl;
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	mysql_query (connect,"select * from tt;");
	res_set = mysql_store_result(connect);
	unsigned int numrows = mysql_num_rows(res_set);
	for(int i = 0; i < numrows; i++){
		row = mysql_fetch_row(res_set);
		cout<<row[0]<<"-"<<row[1]<<"-"<<row[2]<<endl;
	}
	mysql_close(connect);
	return 0;
}