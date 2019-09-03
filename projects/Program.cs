using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
         static double W(int k,int[]a)
        {
            double val = (1 / a[k]);
            if (k == 0)
                return val;
            return val + W((k-1), a);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Podaj liczbę całkowitą n: ");
            int n = Convert.ToInt32(Console.ReadLine());
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = i+1;
            }
            double wynik = W(n - 1, a);
            Console.WriteLine("Suma szeregu n=" + n + " wynosi:" + $"{wynik:0.00##}");
            Console.ReadKey();
        }
    }
}
