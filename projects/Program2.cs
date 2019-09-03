using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp13
{
    class Program
    {

        
static X Function<X>(X a2, X a1, X b2, X b1)
        {
            X result;
            X f, g;
            f = Convert.ToSingle(Math.Pow(Math.Abs((dynamic)a2 - a1), 2));
            g = Convert.ToSingle(Math.Pow(Math.Abs((dynamic)b2 - b1), 2));
            result = Convert.ToSingle(Math.Sqrt((dynamic)f + g));
            return (result);
        }

class Triangle<T>
        {
	private float a, b, c;
    private float p;
    private float x, y, z;
    private float x_2, x_1, y_2, y_1;
    private double alpha, bravo, charlie, delta, echo, foxtrot;
    private float[,] arr_ay = new float[3, 2];
    private float h1, h2, h3;
    private float[] C = new float[2];
    private float[] I = new float[2];
    private float I_calc1, I_calc2;
    private float ma, mb, mc;

            public Triangle(float a, float b, float c)
            {
                this.a = a;
                this.b = b;
                this.c = c;
            }
          public  float edges()
            {
                return (a + b + c);
            }
         public  float surface_area()
            {
                p = edges() / 2;
                return Convert.ToSingle(Math.Sqrt(p * (p - a) * (p - b) * (p - c)));
            }
          public void Abc()
            {
                C[0] = (arr_ay[0,0] + arr_ay[1,0] + arr_ay[2,0]) * 1 / 3;
                C[1] = (arr_ay[0,1] + arr_ay[1,1] + arr_ay[2,1]) * 1 / 3;
                I[0] = (arr_ay[0,0] + arr_ay[1,0] + arr_ay[2,0]) / edges();
                I[1] = (arr_ay[0,1] + arr_ay[1,1] + arr_ay[2,1]) / edges();
                I_calc1 = 1 / ((1 / h1) + (1 / h2) + (1 / h3));
                Console.WriteLine("Promien kola wpisanego:r = " + I_calc1);
                I_calc2 = a * b * c / (2 * surface_area());
                Console.WriteLine("Promien kola opisanego: R = " + (I_calc2 / 2));
                mc = Convert.ToSingle(Math.Sqrt(((2 * Math.Pow(b, 2)) + (2 * Math.Pow(c, 2)) - (Math.Pow(a, 2))) / 4));
                mb = Convert.ToSingle(Math.Sqrt(((2 * Math.Pow(a, 2)) + (2 * Math.Pow(c, 2)) - (Math.Pow(b, 2))) / 4));
                ma = Convert.ToSingle(Math.Sqrt(((2 * Math.Pow(a, 2)) + (2 * Math.Pow(b, 2)) - (Math.Pow(c, 2))) / 4));
                Console.WriteLine("Mediana:ma = " + mb);
                Console.WriteLine("Mediana:mb = " + ma);
                Console.WriteLine("Mediana:mc = " + mc);
            }
           public void show()
            {
                h1 = 2 * surface_area() / c;
                h2 = 2 * surface_area() / b;
                h3 = 2 * surface_area() / a;
                bravo = Convert.ToDouble(2 * surface_area() / a) / Convert.ToDouble(b);//h=2A/b
                echo = bravo;
                bravo = Math.Asin(bravo) * 180 / Math.PI;
                alpha = Convert.ToDouble(2 * surface_area() / b) / Convert.ToDouble(c);//wpisac roznice
                delta = alpha;
                alpha = Math.Asin(alpha) * 180 / Math.PI;
                charlie = Convert.ToDouble(2 * surface_area() / c) / Convert.ToDouble(a);
                foxtrot = charlie;
                charlie = Math.Asin(charlie) * 180 / Math.PI;
                if ((charlie + bravo) < alpha)
                {
                    delta = 180 - Math.Asin(delta) * 180 / Math.PI;
                    alpha = delta;
                }
                else if ((charlie + alpha) < bravo)
                {
                    echo = 180 - Math.Asin(echo) * 180 / Math.PI;
                    bravo = echo;
                }
                else if ((alpha + bravo) < charlie)
                {
                    foxtrot = 180 - Math.Asin(foxtrot) * 180 / Math.PI;
                    charlie = foxtrot;
                }
                Abc();
                Console.WriteLine("Obwod/Perimeter:p = " + edges());
                Console.WriteLine("polobwod/Semiperimeter:s = " + edges() / 2);
                Console.Write("Boki/Sides: ");
                Console.Write("  a = " + b);
                Console.Write("  b = " + c);
                Console.WriteLine("  c = " + a);
                Console.WriteLine("Kat:Alpha = " + charlie + "°");
                Console.WriteLine("Kat:Bravo = " + bravo + "°");
                Console.WriteLine("Kat:Charlie = " + alpha + "°");
                Console.WriteLine("Wysokosc:H1 = " + h2);
                Console.WriteLine("Wysokosc:H2 = " + h1);
                Console.WriteLine("Wysokosc:H3 = " + h3);
                int n = 0;
                Console.Write("Centroid: " + "<" + C[n]);
                n++;
                Console.WriteLine("," + C[n] + ">");
                n = 0;
                Console.Write("Incenter: " + "<" + I[n]);
                n++;
                Console.WriteLine("," + I[n] + ">");

            }
           public void InnaFunkcja()
            {
                
                for (int i = 0; i < 3; i++)
                    {
                        int n = 0;
                    Console.Clear();
                    Console.WriteLine("Podaj Wspolzedne krawedzi");
                    Console.Write("Krawedz:" + (i + 1) + ": <x1,y1>: ");
                        x_1=Convert.ToSingle(Console.ReadLine());
                        arr_ay[i,n] = x_1;
                        n++;
                        y_1=Convert.ToSingle(Console.ReadLine());
                        arr_ay[i,n] = y_1;
                    Console.Write("Krawedz:" + (i + 1) + ": <x2,y2>: ");
                        x_2 = Convert.ToSingle(Console.ReadLine());
                        y_2 = Convert.ToSingle(Console.ReadLine());
                        if (i == 0)
                        {
                            x = Function<float>(x_2, x_1, y_2, y_1);
                        }
                        if (i == 1)
                        {
                            y = Function<float>(x_2, x_1, y_2, y_1);
                        }
                        if (i == 2)
                        {
                            z = Function<float>(x_2, x_1, y_2, y_1);
                        }
                    }
                Console.Clear();
                Console.WriteLine();
                    for (int i = 0; i < 3; i++)
                    {
                        int n = 0;
                        Console.Write("<" + arr_ay[i,n]);
                        n++;
                        Console.WriteLine(',' + arr_ay[i,n] + ">");
                    }

                

            }
            ~Triangle()
            {
              
            }
        }
        static void Main(string[] args)
        {
            Triangle<float> foo = new Triangle<float>(5.0f, 3.0f, 4.0f);
            foo.InnaFunkcja();
            Console.WriteLine("Pole:T = " + foo.surface_area());
            foo.show();
            Console.ReadKey();
        }
    }
}
