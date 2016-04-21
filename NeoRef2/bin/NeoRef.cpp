#include <iostream>
#include "mod_add.h"

using namspace std;

string ee = "ERROR CON LOS COMANDOS";

int main(int argc, char *argv[]){
	try{
		if(argc == 1){
			return 0;
		}
		string fun(argv[1]);
		if(fun == "add"){
			if(argc < 3){
				string e = "EL comando add necesita un subcomando (all) o una ruta de archivo";
				throw(e);
			}
			string fun2(argv[2]);
			if(fun2 == "all"){
				if(argc < 4){
					string e = "El comando add all necesita una ruta de archivo"
					throw(e);
				}
				if(argc > 4) throw(ee);
				string fun3(argv[3]);
				add_all(fun3);
			}
			else{
				if(argv > 3) throw(ee);
				add_new(fun2);
			}
		}
	}
	catch(string e){cout<<e<<endl;}
	catch(...){cout<<"Ocurrio algo..."<<endl}
}