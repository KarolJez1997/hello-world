using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace ConsoleApp10
{
    class Program
    {
        static void Pascal(int iter)
        {
            int rows;
            rows = iter;
            if(rows==1)
            {
                rows = iter;
            }
            for (int j = 0; j <iter; j++)
            {
                for(int k = rows; k>0; k--)
                {
                    Console.Write("   ");
                    if(k==1)
                    {
                       for(int i=0; i<=j; i++)
                        {
                                if (Dwumian2(j,i) < 10)
                                {
                                    Console.Write(Dwumian2(j, i) + "     ");
                                }
                                else if((Dwumian2(j, i) > 9)&& (Dwumian2(j, i) < 100))
                                {
                                    Console.Write(Dwumian2(j, i) + "    ");
                                }
                                else if((Dwumian2(j, i) > 99) && (Dwumian2(j, i) < 1000))
                                {
                                    Console.Write(Dwumian2(j, i) + "   ");
                                }
                                else if ((Dwumian2(j, i) > 999) && (Dwumian2(j, i) < 10000))
                                {
                                Console.Write(Dwumian2(j, i) + "  ");
                                }
                                else if ((Dwumian2(j, i) > 9999) && (Dwumian2(j, i) < 100000))
                                {
                                Console.Write(Dwumian2(j, i) + " ");
                                }
                        }

                    }
                }
                Console.Write(Environment.NewLine);
                rows--;
            }

        }
        static long Dwumian2(int n, int k)
        {
            double wynik= (silnia(n) / (silnia(k) * silnia(n - k)));
            if (wynik % 3 == 0)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                return (silnia(n) / (silnia(k) * silnia(n - k)));
            }
            else
            {
                Console.ResetColor();
                return (silnia(n) / (silnia(k) * silnia(n - k)));
                
            }
        }
        static double Dwumian1(int n, int k)
        {
            if (n == 1) return (silnia(n) / (silnia(k) * silnia(n - k)));
            return ((silnia(n) / (silnia(k)*silnia(n-k))) + Dwumian1(n - 1, k));
        }

        static double Potega(int a, int n)
        {
            if (n == 0) return 1;
            return a * Potega(a, n - 1);
        }

        static long silnia(int n)
        {
            if (n < 2)
                return 1;
            if (n==0)
            {
                return 1;
            }
            else
            {
                return n * silnia(n - 1);
            }
        }
        static double Suma(int n, int k)
        {
            if (n == 1) return 1/silnia(k);
            return ((1 / silnia(k)) + Suma(n - 1, k));
        }

        static double Suma2(int n, int k)
        {
            if (n == 1) return k / Potega(n,k);
            return ((k / Potega(n,k) + Suma2(n - 1, k)));
        }
        static void Main(string[] args)
        {
            int n;
            int k;
            int iteracja;

            Console.WriteLine("Podaj liczbę n: ");
            n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Podaj liczbę k: ");
            k = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Iteracja: ");
            iteracja = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Suma: " +Suma(n,k));
            Console.WriteLine("Suma2: " + Suma2(n, k));
            Console.WriteLine("Dwumian1: " + Dwumian1(n, k));
            Console.WriteLine("Dwumian2: " + Dwumian2(n, k));
            Console.WriteLine("-----------------------------");
            Pascal(iteracja);

            Console.ReadKey();
        }
    }
}
