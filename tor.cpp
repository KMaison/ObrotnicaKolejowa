#include "Tor.h"
#include <iostream>

using namespace std;
void Tor::inicjalizuj()
{
	pierwszy = NULL;
	liczba_wagonow_na_torze = 0;
	liczba_wagonow = 0;
}

void Tor::wypelnij()
{
	int *tablica = (int*) malloc(liczba_wagonow * sizeof(int));
	for (int i = 0; i < liczba_wagonow; i++)
	{
		cin >> tablica[i];
	}
	for (int i = liczba_wagonow - 1; i >= 0; i--)
	{
		dodaj(tablica[i]);
	}
		free(tablica);
}

void Tor::dodaj(int id)
{
	Wagon* tmp = new Wagon;
	tmp->id = id;
	tmp->nastepny = pierwszy;
	pierwszy = tmp;
	liczba_wagonow_na_torze++;
}

void Tor::usun()
{
	if (pierwszy)
	{
		Wagon *tmp = pierwszy;
		pierwszy = pierwszy->nastepny;
		delete tmp;
		liczba_wagonow_na_torze--;
	}
	/*Wagon *tmp;
	if (pierwszy != NULL)
	{
		tmp = pierwszy->nastepny;
		delete pierwszy;
		//free(pierwszy); //?
		tmp = pierwszy;
		liczba_wagonow_na_torze--;
	}*/
}


void Tor::wypisz()
{
	cout << liczba_wagonow_na_torze << " ";
	while (liczba_wagonow_na_torze)
	{
		cout << pierwszy->id << " ";
			usun();
	}

}

