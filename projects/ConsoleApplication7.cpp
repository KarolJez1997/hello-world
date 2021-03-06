// ConsoleApplication7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

constexpr int PIERWSZY_PROG = 3089;
constexpr int DRUGI_PROG = 85528;

enum PROGI {ZERO,RAZ,DWA};
PROGI decyzja;

bool nowe_obliczenie;
char odp;


template<class X>
X obliczenia(X dochod2)
{
	X podatek;
	if(dochod2 <= (PIERWSZY_PROG))
	{
		decyzja = ZERO;
	}
	else if((dochod2 > PIERWSZY_PROG) && (dochod2 <= DRUGI_PROG))
	{
		decyzja = RAZ;
	}
	else if(dochod2 > DRUGI_PROG)
	{
		decyzja = DWA;
	}
	switch(decyzja)
	{
	case ZERO:
		podatek = 0;
		break;
	case RAZ:
		podatek = (0.18 * dochod2) - 556.02;
		break;
	case DWA:
		podatek = (032 * dochod2) - DRUGI_PROG + 14839.02;
		break;
	}
	return podatek;
}

void funkcja1()
{
	cout << "Podaj cochod: ";
	double *zmienna = new double;
	cin >> *zmienna;
	cout << endl;
	cout << "Podatek: ";
	cout << obliczenia<float>(*zmienna);
	delete[] zmienna;
}

int main()
{
		do
		{
			funkcja1();
			cout << " Nowy podatek?(t): " << endl;
			cin >> odp;
		} while ((odp != 't') == false);
	_getch();
}
