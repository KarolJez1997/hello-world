#include"pch.h"
#include<iostream>
#include <string>
#include <conio.h>

using namespace std;

int x, y, z;
int x_3;
int x_4[3];
int y_4[] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
int y_3;


struct data
{
	int dzien;
	int rok;
	string const miesiace[12] = { "Styczen","Luty","Marzec","Kwiecien","Maj","Czerwiec","Lipiec","Sierpien","Wrzesien","Pazdziernik","Listopad","Grudzien" };
    
}kalendarz;

struct liczby
{
	string const od_1_do_19[19] = { "Raz","Dwa","Trzy","Cztery","Piec","Szesc","Siedem","Osiem","Dziewiec","Dziesiec","Jedenascie","Dwanascie","Trzynascie","Czternasie","Pietnascie","Szesnascie","Siedemnascie","Osiemnascie","Dziewietnascie" };
	string const dziesiatki[9] = { "Dziesiec","Dwadziescia","Trzydziesci","Czterdziesci","Piecdziesiat","Szescdziesiat","Siedemdziesiat","Osiemdziesiat","Dziewiecdziesiat" };
	string const setki[9] = { "Sto","Dwiescie","Trzysta","Czterysta","Piecset","Szescset","Siedemset","Osiemset","Dziewiecset" };
	string const tysiace[3] = { "Tysiac","Tysiace","Tysiecy" };
	string const miliony[3] = { "Milion","Miliony","Milionow" };
	string const miliard[3] = { "Miliard","Miliardy","Miliardow" };
}slowa;

void funkcjaliczby(int x1,int x2[])
{
	if (x1 < 20)
	{
		cout << slowa.od_1_do_19[x1 - 1] << endl;
	}
	else if ((x1 > 20) && (x1 < 100))
	{
		if (x2[2] != 0)
		{
			cout << slowa.dziesiatki[x2[1] - 1] << slowa.od_1_do_19[x2[2] - 1] << endl;
		}
		else
		{
			cout << slowa.dziesiatki[x2[1] - 1] << endl;
		}
	}
	else if ((x1 > 99) && (x1 < 1000))
	{
		if ((x2[2] != 0) && (x2[1] != 0))
		{
			if(x2[1]!=1)
			cout << slowa.setki[x2[0] - 1] << slowa.dziesiatki[x2[1] - 1] << slowa.od_1_do_19[x2[2] - 1]<<endl;
			else
		cout << slowa.setki[x2[0] - 1] << slowa.od_1_do_19[x2[2] +9] << endl;
		}
		else if ((x2[2] == 0) && (x2[1] != 0))
		{
			cout << slowa.setki[x2[0] - 1] << slowa.dziesiatki[x2[1] - 1] << endl;
		}
		else if ((x2[2] == 0) && (x2[1] == 0))
		{
			cout << slowa.setki[x2[0] - 1] << endl;
		}
		else if ((x2[2] != 0) && (x2[1] == 0))
		{
			cout << slowa.setki[x2[0] - 1] << slowa.od_1_do_19[x2[2] - 1] << endl;
		}
	}
}



int main()
{
	do
	{
		cout << "Dzien:";
		cin >> x;
	} while (x>31||x<1);
	cout << endl;
	
	do
	{
		cout << "Miesiac:";
		cin >> y;
	} while (y>12||y<1);
	cout << endl;
	cout << "Rok: ";
	cin >> z;
	if ((z % 4 == 0 && z % 100 != 0) || z % 400 == 0)
	{
		cout << "Rok jest przestepny" << endl;
		if (y == 2)
		{
			while ((x > 29)||(x<1))
			{
				cout << "Podaj ponownie dzien:";
				cin >> x;
				cout << endl;
			}
		}
		else if ((y==4||y==6||y==9||y==11)&&(x>29))
		{
			while ((x > 30)||(x<1))
			{
				cout << "Podaj ponownie dzien:";
				cin >> x;
				cout << endl;
			}
		}
	}
	else
	{
		cout << "Rok nie jest przestepny" << endl;
		if (y == 2)
		{
			while ((x > 28)||(x<1))
			{
				cout << "Podaj ponownie dzien:";
				cin >> x;
				cout << endl;
			} 
		}
		else if((y == 4 || y == 6 || y == 9 || y == 11)&&(x>30))
		{
			while ((x > 30) || (x < 1))
			{
				cout << "Podaj ponownie dzien:";
				cin >> x;
				cout << endl;
			} 
		}
		
	}
	cout<< endl;
	kalendarz.dzien = x;
	kalendarz.rok = z;
	cout << kalendarz.dzien << " " << kalendarz.miesiace[y - 1] << " " << kalendarz.rok;
	cout << "Podaj liczbe" << endl;
	cin >> y_3;
	for (;;)
	{
		static int n = 0;
		y_4[11] = y_3 % 10;
		y_4[10] = y_3 / 10 % 10;
		y_4[9] = y_3 / 100 % 10;
		y_4[8] = y_3 / 1000 % 10;
		y_4[7] = y_3 / 10000 % 10;
		y_4[6] = y_3 / 100000 % 10;
		y_4[5] = y_3 / 1000000 % 10;
		y_4[4] = y_3 / 10000000 % 10;
		y_4[3] = y_3 / 100000000 % 10;
		y_4[2] = y_3 / 1000000000 % 10;
		y_4[1] = y_3 / 10000000000 % 10;
		y_4[0] = y_3 / 100000000000 % 10;
		do
		{
			x_4[0] = y_4[0 + n];
			x_4[1] = y_4[1 + n];
			x_4[2] = y_4[2 + n];
			y_3 = ((x_4[0] * 100) + (x_4[1] * 10) + x_4[2]);
			if (x_4[2] != 0)
			{
				funkcjaliczby(y_3, y_4);
				if (y_3 == 1)
				{
					if(n==0)
					cout << slowa.miliard[0];
					if (n == 3)
						cout << slowa.miliony[0];
					if (n == 9)
						cout << slowa.tysiace[0];
				}
				else if ((y_3 > 1) && (y_3 < 5)) 
				{
					if (n == 0)
					cout << slowa.miliard[1];
					if (n == 3)
						cout << slowa.miliony[1];
					if (n == 9)
						cout << slowa.tysiace[1];
				}
				else if (y_3 > 4)
				{
					if (n == 0)
					cout << slowa.miliard[2];
					if (n == 3)
						cout << slowa.miliony[2];
					if (n == 9)
						cout << slowa.tysiace[2];
				}
			}
			n = n + 3;
		} while (n < 9);
	}
	_getch();
	return 0;
}