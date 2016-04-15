#include <iostream>

using namespace std;

#define FECHA_NULL 20130306;
#define ID_NULL 0;

typedef string ID;
typedef int RefDate;
typedef int Click;

class Referido{
	public:
		Referido();
		Referido(ID id, RefDate ini, RefDate lastClick);
	private:
		ID idRef;
		RefDate fechaIni;
		RefDate lastClick;
};


Referido::Referido(){
	ID_NULL = 0;
	fechaIni = FECHA_NULL;
	lastClick = FECHA_NULL; 
}

Referido::Referido(ID id, RefDate ini, RefDate lastClick){
	this-> idRef = id;
	this-> fechaIni = ini;
	this-> lastClick = lastClick;
}