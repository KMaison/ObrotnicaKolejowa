#pragma once
#include "Wagon.h"
#include "Tor.h"
struct Obrotnica
{
#define MAX_OBROTNICY 10

	int wagony[MAX_OBROTNICY];
	int i; //i-te miejsce na obrotnicy od 0 do 9
	int wskazuje_na;
	int ile_o;  //ile jest wagonow na obrotnicy
	void inicjalizacja();
	void obrot_r(int ile, int n);
	void obrot_l(int ile, int n);
	void dodaj_na_obrotnice(int ile, Tor *tor);

	void usun(int ile, Tor *tor);
};