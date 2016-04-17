#include <iostream>
#include <ctime>
#include "Referido.h"

using namespace std;


RefDate getActualTime(){
	time_t t = time(0);
  	struct tm * now = localtime(&t);
  	int year = now->tm_year + 1900;
  	int day = now->tm_mday;
  	int mes = now->tm_mon + 1;
  	return (year * 10000) + (mes * 100) + day;
}