#include <iostream>
#include <ctime>
#include "Referido.h"
#include <map>

using namespace std;

typedef int Day;

int Enero = 0;
int Febrero = 3;
int Marzo = 3;
int Abril = 6;
int Mayo = 1;
int Junio = 4;
int Julio = 6;
int Agosto = 2;
int Setiembre = 5;
int Octubre = 0;
int Noviembre = 3;
int Diciembre = 5;

enum Dias{LUNES,MARTES,MIERCOLES,JUEVES,VIERNES,SABADO,DOMINGO};
enum Meses{ENERO,FEBRERO,MARZO,ABRIL,MAYO,JUNIO,JULIO,AGOSTO,SETIEMBRE,OCTUBRE,NOVIEMBRE,DICIEMBRE};

int getMes(int mes){
	switch(mes){
		case ENERO: return Enero;
		case FEBRERO: return Febrero;
		case MARZO: return Marzo;
		case ABRIL: return Abril;
		case MAYO: return Mayo;
		case JUNIO: return Junio;
		case JULIO: return Julio;
		case AGOSTO: return Agosto;
		case SETIEMBRE: return Setiembre;
		case OCTUBRE: return Octubre;
		case NOVIEMBRE: return Noviembre;
		case DICIEMBRE: return Diciembre;
		default: return 0;
	}
}

RefDate getActualTime(){
	time_t t = time(0);
  	struct tm * now = localtime(&t);
  	int year = now->tm_year + 1900;
  	int day = now->tm_mday;
  	int mes = now->tm_mon + 1;
  	return (year * 10000) + (mes * 100) + day;
}

Day getDay(RefDate date){
	int day = date % 100;
	date = date / 100;
	int mes = date % 100;
	int year = date / 100;
	return (dia + getMes(mes) + (year % 100) + ((year % 100) / 4) + 6) % 7;
}
