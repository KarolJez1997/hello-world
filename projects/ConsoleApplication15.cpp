// ConsoleApplication15.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

struct Data
{
	int rok;
	int miesiac;
	int dzien;
	int data_jako_liczba;
};
int liczba_dat;
int dni_w_miesiacach[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
Data * daty;
Data tymczasowa_data;

int main()
{
	srand(time(NULL));
	cout << "Podaj liczbe dat do wylosowania: ";
	cin >> liczba_dat;

	daty = new Data[liczba_dat];
	for (int i = 0; i < liczba_dat; i++)
	{
		daty[i].rok = rand() % 2100;
		daty[i].miesiac = rand() % 12 + 1;
		if (daty[i].rok % 4 == 0 && daty[i].miesiac == 2)
		{
			daty[i].dzien = rand() % dni_w_miesiacach[i] + 1;
		}
		else
		{
			daty[i].dzien = rand() % (dni_w_miesiacach[i] + 1) + 1;
		}

		daty[i].data_jako_liczba = daty[i].rok * 10000 + daty[i].miesiac * 100 + daty[i].dzien;
	}
	for (int i = liczba_dat - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (daty[j].data_jako_liczba > daty[j + 1].data_jako_liczba)
			{
				tymczasowa_data = daty[j];
				daty[j] = daty[j + 1];
				daty[j + 1] = tymczasowa_data;
			}
		}
	}
	for (int i = 0; i < liczba_dat; i++)
	{
		cout << daty[i].rok << "-" << daty[i].miesiac << "-" << daty[i].dzien << endl;
	}
	_getch();
}
