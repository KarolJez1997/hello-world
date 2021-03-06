#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

bool nowy_x;
bool nowy_swap;
bool nowy_wielomian;
float miejsce_zerowe;
float x;
float zmienna;
int dlugosc;
float * W;
float * P;
char odp;
int liczba;

void tabela_W()
{
	W = new float[dlugosc];
	cout << "Zawartosc tabelki W: " << endl;
	for (int i = 0; i < dlugosc; i++)
	{
		cin >> zmienna;
		W[i] = zmienna;
	}
}

void tabela_P()
{
	P = new float[dlugosc];
	P[0] = W[0];
	for (int i = 1; i < dlugosc; i++)
	{
		P[i] = P[i - 1] * x + W[i];
	}
}

void wynik()
{
	cout << "wynik: " << P[dlugosc - 1] << endl;
}

void zamiana()
{
	do
	{
		double bufor;
		cout << endl;
		cout << "Wybierz pare do zamiany(od 1 do " << dlugosc - 1 << ")";
		cin >> liczba;
		bufor = W[liczba-1];
		W[liczba-1] = W[liczba];
		W[liczba] = bufor;
		cout << endl;
		tabela_P();
		wynik();
		cout << endl;
		do
		{
			cout << "nowa zamiana?(t/n): ";
			cin >> odp;
		} while ((odp == 't' || odp == 'n') == false);
		odp == 't' ? nowy_swap = true : nowy_swap = false;
	} while (nowy_swap);
}

void horner()
{
	nowy_x = true;
	nowy_wielomian = true;
	do
	{
		cout << "Podaj dlugosc wielomianu W() : ";
		cin >> dlugosc;
		tabela_W();
		do
		{
			cout << "Podaj wartosc x: ";
			cin >> x;
			tabela_P();
			wynik();
			do
			{
				cout << "czy zamienic miejsca?(t/n): ";
				cin >> odp;
			} while ((odp == 't' || odp == 'n') == false);
			if (odp == 't')
			{
				zamiana();
			}
			delete[] P;
			do
			{
				cout << "nowy x?(t/n): ";
				cin >> odp;
			} while ((odp == 't' || odp == 'n') == false);
			odp == 't' ? nowy_x = true : nowy_x = false;
		} while (nowy_x);
		delete[] W;
		do
		{
			cout << "nowy wielomian?(t/n): ";
			cin >> odp;
		} while ((odp == 't' || odp == 'n') == false);
		odp == 't' ? nowy_wielomian = true : nowy_wielomian = false;
	} while (nowy_wielomian);

}

int silnia(int n)
{
	if (n <= 1)
		return 1;
	return n * silnia(n - 1);
}

int main(int argc, char* argv[])
{
	if ((argv[0] && argv[1]) != 0)
	{
		float ia = strtol(argv[1], NULL, 10);
		float ib = strtol(argv[2], NULL, 10);
		cout << ia + ib << endl;
	}
	cout << silnia(8);
	cout << endl;
	horner();
	cout << argv[0] << std::endl;
	_getch();
	return 0;
}
//1 -3 5 -15