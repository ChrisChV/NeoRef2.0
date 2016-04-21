#ifndef REFERIDO_H
#define REFERIDO_H

#include <iostream>

using namespace std;

int FECHA_NULL = 20130306;
string ID_NULL = "0";
#define SEMANA_NULL "0000000"

typedef string ID;
typedef int RefDate;
typedef int Click;
typedef string SemanaBin;

class Referido{
	public:
		Referido();
		Referido(ID id, RefDate ini, RefDate lastClick, SemanaBin semanaBin);
		ID idRef;
		RefDate fechaIni;
		RefDate lastClick;
		SemanaBin semanaBin;
};


Referido::Referido(){
	idRef = ID_NULL;
	fechaIni = FECHA_NULL;
	lastClick = FECHA_NULL; 
	semanaBin = SEMANA_NULL;
}

Referido::Referido(ID id, RefDate ini, RefDate lastClick, SemanaBin semanaBin){
	this-> idRef = id;
	this-> fechaIni = ini;
	this-> lastClick = lastClick;
	this-> semanaBin = semanaBin;
}

#endif