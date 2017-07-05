#pragma once
#include "Wagon.h"

struct Tor //stos
{
	int liczba_wagonow; //ktora wjechala na poczatku
	int liczba_wagonow_na_torze; //obecnie


	Wagon *pierwszy;

	void inicjalizuj();
	

	void wypelnij(); //funckcja do wypelnienia jednorazowo id * liczba wagonow
	void dodaj(int id); //na tor
	void usun();
	void wypisz();
};