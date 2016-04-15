#include <iostream>
#include <fstream>
#include <vector>
#include "Referido.h"

using namspace std;

Referido stringToReferido(string line){
	int estado = 0;
	ID id = ID_NULL;
	RefDate ini = FECHA_NULL;
	RefDate lastClick = FECHA_NULL;
	string temp;
	for(auto iter = line.begin(); iter != line.end(); ++iter){
		if(*iter != ',') temp.push_back(*iter);
		else{
			if(estado == 0) id = temp;
			else if(estado == 1) ini = stoi(temp);
			else if(estado == 2){
				lastClick = stoi(temp);
				break;
			}
			temp.clear();
			estado++;
		}
	}
	return Referido(id,ini,lastClick);
}

vector<Referido> allRef(string file){
	try{
		ifstream archivo(file.c_str());
		if(archivo.fail()){
			string e = "EL archivo " + file + " no existe o no se puede abrir";
			throw(e);
		}
		vector<Referido> res;
		char line[120];
		while(archivo.getline(line,120)){
			string temp(line);
			res.push_bakc(stringToReferido(temp));
		}
		return res;
	}
}


