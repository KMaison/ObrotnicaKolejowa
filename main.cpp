#include <iostream>
#include "Obrotnica.h"
#include "Tor.h"
#include "Wagon.h"

using namespace std; //!

int main()
{
	Obrotnica obrotnica;
	obrotnica.inicjalizacja();

	int liczba_torow, ile;
	cin >> liczba_torow;  //1)wpisz ilosc torow

	Tor *tor;
	tor = (Tor*)malloc(liczba_torow * sizeof(Tor));

	for (int i = 0; i < liczba_torow; i++)
	{
		
		tor[i].inicjalizuj(); //zeruje stos

		cin >> tor[i].liczba_wagonow;

		tor[i].wypelnij(); //wpisz id wagonow
	}
	int ilosc_instrukcji, instrukcja = 0;
	char wybor;
	//cout << "Podaj ilosc instrukcji: ";
	cin >> ilosc_instrukcji;  //wpisz ilosc instrukcji

	
	while (instrukcja < ilosc_instrukcji)
	{
		//cout << "z/o/w/j - ";
		cin >> wybor;
		switch (wybor)
		{
		case 'z':
		{
			cin >> ile;
			obrotnica.obrot_r(ile, liczba_torow);
			//przesu� obrotnic� o liczba tor�w zgodnie z ruchem wskaz�wek zegara
			break;
		}
		case 'o': 
		{//przesu� obrotnic� o liczba tor�w odwrotnie do ruchu wskaz�wek zegara
			cin >> ile;
			obrotnica.obrot_l(ile, liczba_torow);
			break;
		}
		case 'w': //wprowad� liczba wagon�w na obrotnic�(wprowadzamy do pojemno�ci obrotnicy i nie wi�cej ni� liczba wagon�w na torze)
		{
			cin >> ile;
			obrotnica.dodaj_na_obrotnice(ile, &tor[obrotnica.wskazuje_na]);
			break;
		}
		case 'j': // wyjed� liczba wagonami z obrotnicy(nie mo�na wyprowadzi� wi�cej ni� liczba wagon�w na obrotnicy)
		{
			cin >> ile;
			obrotnica.usun(ile, &tor[obrotnica.wskazuje_na]);
		break;
		}
		default: break;
		}
		instrukcja++;
	}

	//wypisanie
	cout<<obrotnica.i+1<<" ";
	for (int i = obrotnica.i ; i >=0; i--)
	{
		cout<<obrotnica.wagony[i]<<" ";
	}
	cout <<endl;
	for (int i = 0; i < liczba_torow; i++)
	{
		while (obrotnica.wskazuje_na >= liczba_torow)
			obrotnica.wskazuje_na -= liczba_torow;
		tor[obrotnica.wskazuje_na].wypisz();
		cout << endl;
		obrotnica.wskazuje_na++;
	}
	free(tor);
	return 0;
}