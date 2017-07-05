#include "Obrotnica.h"
#include "Tor.h"


void Obrotnica::inicjalizacja()
{
	ile_o = 0;
	i = -1;
	wskazuje_na = 0;
}

void Obrotnica::obrot_r(int ile, int n)
{
	wskazuje_na += ile; //torow jest na miejscach od 0 do n-1
	while (wskazuje_na > n - 1) //wskazywanie ma zmniejszac sie az do wtedy gdy wskazuje_na<n-1
		wskazuje_na -= n;
}

void Obrotnica::obrot_l(int ile, int n)
{
	wskazuje_na -= ile;
	while (wskazuje_na < 0)
		wskazuje_na += n;
}

void Obrotnica::dodaj_na_obrotnice(int ile, Tor *tor)
{
	if (ile > tor->liczba_wagonow_na_torze)
		ile = tor->liczba_wagonow_na_torze;

	while (ile > 0 && i < MAX_OBROTNICY-1) //mozna dodac o ile i<od 9
	{ //bo nastepne zajmie miejsce 9
		i++;
		wagony[i] = tor->pierwszy->id;
		tor->usun();
		ile_o++;
		ile--;
	}
}

void Obrotnica::usun(int ile, Tor * tor)
{
	while (ile > 0 && i >= 0) //usunac mozna ja na obrotnicy cos jest czyli
	{ //i>=0
		tor->dodaj(wagony[i]);
		ile_o--;
		i--;
		ile--;
	}
}


