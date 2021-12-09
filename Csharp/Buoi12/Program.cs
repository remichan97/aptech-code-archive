using System;
using cs = System.Console;

namespace Buoi12
{
    class Program
    {
        static void Main(string[] args)
        {
            //switch-case-goto
            int tuoi;
            string name;
            cs.WriteLine("Enter your name");
            name = cs.ReadLine();
            cs.WriteLine("Enter your age");
            tuoi = Convert.ToInt32(cs.ReadLine());
            switch (tuoi)
            {
                case 1:
                    cs.WriteLine("Welcome " +name);
                    break;
                default:
                    do
                    {
                        cs.WriteLine("To continue, you must be at least 20 years old");
                        cs.WriteLine("Enter your age again:");
                        tuoi = Convert.ToInt32(cs.ReadLine());
                    } while (tuoi < 20);
                    goto case 1;
            }
        }
    }
}
