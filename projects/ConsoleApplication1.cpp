// ConsoleApplication1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//
#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "iostream"
#include "math.h"
#include "windows.h"

using namespace std;

class Nawijak
{
private:
	float x;
    float predkosc; //obr na min
	float pi;
	float szybkosc;//metry na 10 ms
	float papier;//metry
	float srednica;//metry
	float obw_tulejki; //obwod w metrach
	int licznik_etykiet;
	int liczba_etykiet;
	float dlugosc_etykiet;//metry
	float metry_na_hamulcu;
	float metry_na_nawijaku;
public:
	Nawijak(float x=0, float predkosc = 0, float pi=0 , float szybkosc = 0, float papier = 0, float srednica = 0, float obw_tulejki = 0, int licznik_etykiet = 0, int liczba_etykiet = 0, float dlugosc_etykiet = 0, float metry_na_hamulcu = 0, float metry_na_nawijaku = 0)
	{
		this->x = x;
		this->predkosc = predkosc;
		this->pi = pi;
		this->szybkosc = szybkosc;
		this->papier = papier;
		this->srednica = srednica;
		this->obw_tulejki = obw_tulejki;
		this->licznik_etykiet = licznik_etykiet;
		this->liczba_etykiet = liczba_etykiet;
		this->metry_na_hamulcu = metry_na_hamulcu;
		this->metry_na_nawijaku = metry_na_nawijaku;
	}

	void ruch()
	{
		int pierwszy_prog;
		int drugi_prog;
		cout << "Podaj liczbe etykiet" << endl;
		cin >> liczba_etykiet;
		cout << "Podaj dlugosc papieru" << endl;
		cin >> papier;
		cout << "Podaj dlugosc etykiet" << endl;
		cin >> dlugosc_etykiet;
		cout << "Podaj srednice" << endl;
		cin >> srednica;
		cout << "Podaj pierwszy prog" << endl;
		cin >> pierwszy_prog;
		cout << "Podaj drugi prog" << endl;
		cin >> drugi_prog;
		pi = static_cast<float>(M_PI);
		obw_tulejki = srednica * pi;
		metry_na_hamulcu = (papier + dlugosc_etykiet)*liczba_etykiet;
		while (true)
		{
			static int nr_rolki = 1;
			if (GetKeyState(VK_UP) < 0)
			{
				if (predkosc < 1050 && licznik_etykiet <= pierwszy_prog)
				{
					predkosc = predkosc + 1;
				}
				else
				{
					if (predkosc < 177)
					{
						predkosc = predkosc + 1;
					}
				}
			}
			else if
				(GetKeyState(VK_DOWN) < 0)
			{
				if (predkosc > 0)
				{
					predkosc = predkosc - 1;
					if (predkosc < 0)
						predkosc = 0;
				}
			}
			Sleep(1);

			szybkosc = (predkosc / 60) / 1000;
			x = obw_tulejki * szybkosc;
			metry_na_nawijaku = metry_na_nawijaku + x;
			static float y = dlugosc_etykiet;
			static float mnn = 0;
			mnn = mnn + x;
			if (mnn >= y)
			{
				licznik_etykiet++;
				mnn = 0;
			}
			if (licznik_etykiet >= pierwszy_prog)
			{
				if((obw_tulejki*predkosc)>25)
				predkosc = predkosc - 1;
			}
			if (licznik_etykiet == drugi_prog)
			{
				if (predkosc > 0)
				{
					predkosc = predkosc - 1;
					if (predkosc < 0)
						predkosc = 0;
					Sleep(7000);
					licznik_etykiet = 0;
					nr_rolki = nr_rolki + 1;
				}
			}
			static int petla = 0;
			petla++;
			if (petla == 1000)
			{
				system("cls");
				printf("%s, %f \n", "metry na minute:", obw_tulejki*predkosc);
				printf("%s, %f \n", "metry na nawijaku:", metry_na_nawijaku);
				printf("%s, %f \n", "Obroty na min:", predkosc);
				printf("%s, %f \n", "metry na hamulcu:", metry_na_hamulcu);
				printf("%s, %d \n", "licznik etykiet:", licznik_etykiet);
				printf("%s, %d \n", "numer rolki:", nr_rolki);
				petla = 0;
			}
		}
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	Nawijak *mocny = new Nawijak();
	mocny->ruch();

    return 0;
}

