using System;

namespace Buoi9
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] abc = new int[3];

            try
            {
                abc[3] = 123;
                Console.WriteLine("pokie");
            }
            catch (System.Exception ex)
            {
                Console.WriteLine("Ngoại lệ " +ex.Message);
            }
            finally {
                Console.WriteLine("Chạy qua đây");
            }
        }
    }
}
