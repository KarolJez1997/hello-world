using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp11
{
    class Program
    {
        class Korzen
        {
            protected double a, b;
            public Korzen(double x, double y)
            {
                a = x;
                b = y;
            }
        }

        class Kalkulator : Korzen
        {
            public Kalkulator(double x, double y) : base(x, y)
            {
            }
            public double Mnozenie()
            {
                return a*b; 
            }
            public double Dzielenie()
            {
                return a / b;
            }
            public double Dodawanie()
            {
                return a + b;
            }
            public double Odejmowanie()
            {
                return a - b;
            }

        }
        class Obwod : Korzen
        {
            double dodatkowa_wartosc;
            public Obwod(double x, double y, double w) : base(x, y)
            {
                dodatkowa_wartosc = w;
            }
            public double Kolo()
            {
                return (2 * Math.PI*dodatkowa_wartosc);
            }
            public double Prostokat()
            {
                return (2*(a + b));
            }
            public double Trojkat()
            {
                return (a + b + dodatkowa_wartosc);
            }

        }
        class Pole : Korzen
        {
            double dodatkowa_wartosc;
            public Pole(double x, double y, double w) : base(x, y)
            {
                dodatkowa_wartosc = w;
            }
            public double Kolo()
            {
                return (Math.PI * (dodatkowa_wartosc*dodatkowa_wartosc));
            }
            public double Prostokat()
            {
                return (a*b);
            }
            public double Trojkat()
            {
                return ((1/2)*(a + b + dodatkowa_wartosc));
            }

        }
        class Wizytowka
        {
            private string imie;
            private string nazwisko;
            private string miasto;

            public Wizytowka(string a, string b, string c)
            {
                imie = a;
                nazwisko = b;
                miasto = c;
            }

            public void Metoda()
            {
                int info;
                Console.WriteLine("****************");
                Console.Write("*");
                info = ((14 - imie.Length) / 2);
                for (int i=0; i<info; i++)
                {
                    Console.Write(" ");
                }
                Console.Write(imie);
                for (int i = 0; i < (14-(info+imie.Length)); i++)
                {
                    Console.Write(" ");
                }
                Console.WriteLine("*");

                Console.WriteLine("****************");
                Console.Write("*");
                info = ((14 - nazwisko.Length) / 2);
                for (int i = 0; i < info; i++)
                {
                    Console.Write(" ");
                }
                Console.Write(nazwisko);
                for (int i = 0; i < (14 - (info+nazwisko.Length)); i++)
                {
                    Console.Write(" ");
                }
                Console.WriteLine("*");

                Console.WriteLine("****************");
                Console.Write("*");
                info = ((14 - miasto.Length) / 2);
                for (int i = 0; i < info; i++)
                {
                    Console.Write(" ");
                }
                Console.Write(miasto);
                for (int i = 0; i < (14-(info+miasto.Length)); i++)
                {
                    Console.Write(" ");
                }
                Console.WriteLine("*");
                Console.WriteLine("****************");
                Console.WriteLine();
                Console.WriteLine();
            }

            

        }
        static void Main(string[] args)
        {
            Wizytowka a1 = new Wizytowka("Karol","Alfred","Poznan");
            Wizytowka a2 = new Wizytowka("Adam", "Mickiewicz", "Stambuł");
            Wizytowka a3 = new Wizytowka("Ronald", "McDonald", "Oak Brook");
            Wizytowka a4 = new Wizytowka("Bob", "Goldbaum", "Warszawa");
            a1.Metoda();
            a2.Metoda();
            a3.Metoda();
            a4.Metoda();
            Kalkulator w1 = new Kalkulator(3.0d,7.0d);
            Pole w2 = new Pole(3.0d,4.0d,5.0d);
            Obwod w3 = new Obwod(5.0d,3.0d,2.0d);
            Console.WriteLine("Mnozenie: " + w1.Mnozenie());
            Console.WriteLine("Pole kola: " + w2.Kolo());
            Console.WriteLine("Obwod trojkata: " + w3.Trojkat());


            Console.ReadKey();
        }
    }
}
