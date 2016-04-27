#include <iostream>
#include "mod_add.h"
#include "mod_diario.h"
#include "mod_delete.h"

using namespace std;

string ee = "ERROR CON LOS COMANDOS";

int main(int argc, char *argv[]){
	try{
		if(argc == 1) return 0;
		string fun(argv[1]);
		if(fun == "add"){
			if(argc < 3){
				string e = "EL comando add necesita un subcomando (all) o una ruta de archivo";
				throw(e);
			}
			string fun2(argv[2]);
			if(fun2 == "all"){
				if(argc < 4){
					string e = "El comando add all necesita una ruta de archivo";
					throw(e);
				}
				if(argc > 4) throw(ee);
				string fun3(argv[3]);
				add_all(fun3);
				cout<<"Referidos agregados con exito"<<endl;
			}
			else{
				if(argc > 3) throw(ee);
				add_new(fun2);
				cout<<"Referidos agregados con exito"<<endl;
			}
		}
		else if(fun == "clicks"){
			if(argc < 3){
				string e = "El comando clicks necesita dia de comparacion(hoy,ayer) y la ruta del archivo";
				throw(e);
			}
			if(argc < 4){
				string e = "El comando clicks necesita la ruta del archivo";
				throw(e);
			}
			if(argc > 4) throw(ee);
			string fun2(argv[2]);
			string fun3(argv[3]);
			ProcesarClick(fun2,fun3);
			cout<<"Clicks procesados correctamente"<<endl;
		}
		else if(fun == "delete"){
			if(argc > 3)  throw(ee);
			deleteGrupoRef();
			cout<<"Se eliminaron los referidos correctamente"<<endl;
		}
	}
	catch(string e){cout<<e<<endl;}
	catch(...){cout<<"Ocurrio algo..."<<endl;}
}