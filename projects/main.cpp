#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double pitagoras(float x, float y,float c)
{
    x=fabs(x);
    y=fabs(y);
    x=pow(x,2);
    y=pow(y,2);
    c=x+y;
    return sqrt(c); //kartezjusz nie jest tutaj nam potrzebny
}

int main()
{
    double x2,y2;
    double k;
    double m;
    double x2oblicz,y2oblicz;
    double masa;
    double c;
    double dlugosc;
    double ubytek;

int **tab,n;
	cout<<"Podaj liczbe n i k od 1 do 100000: ";
	do
    {
	cin>>n;
	cout<<"n="<<n<<endl;
	cin>>k;
	cout<<"k="<<k<<endl;
    }while(n>100000 || n<1 || k>100000 || k<1);

	tab = new int *[n]; //przydzielenie pamieci na n wierszy

	for(int i=0;i<n;i++)
    {
		tab[i] = new int[3];

    }//przydzielenie dla kazdego wiersza po 3 komórki
     cout<<"1=m,2=x,3=y"<<endl;
	 for(int i=0; i<n; i++)
     {
         cout<<"wiersz nr: "<<i<<endl;
         do
         {
         cout<<"m(1->1000)="<<endl;
         cin>>m;
         }while(m>1000 || m<1);
         tab[i][0]=m;
         do
         {
         cout<<"x2(-100000->100000)="<<endl;
         cin>>x2;
         }while(x2>100000 || x2<-100000);
         tab[i][1]=x2;
         do
         {
         cout<<"y2(-100000->100000)="<<endl;
         cin>>y2;
         }while(y2>100000 || y2<-100000);
         tab[i][2]=y2;
     }
     for(int i=0; i<n; i++)
     {
      masa+=tab[i][0];
     }
     for(int i=0; i<n; i++)
     {
      x2oblicz=tab[i][1];
      y2oblicz=tab[i][2];
      dlugosc+=pitagoras(x2oblicz,y2oblicz,c);
     }
     ubytek=((1/k)*masa);
     ubytek=ubytek*dlugosc;
     ubytek=ubytek/60;
     cout<<"Ilosc pokarmu mrowek: "<<setprecision(5)<<masa-ubytek<<endl;
     cout<<"Czas transportu: "<<setprecision(4)<<dlugosc*2<<" s"<<endl;


	//zwolnienie pamiêci
	for(int i=0;i<n;i++)
		delete [] tab[i];

	delete [] *tab;
    return 0;
}
