using System;

namespace Buoi7
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            BookList book = new BookList();
            Console.WriteLine("Nhập số lượng sách muốn thêm: ");
            n = Convert.ToInt32(Console.ReadLine());
            for (int i = 1; i <= n; i++)
            {
                Console.WriteLine("Sách cần thêm thứ " + i);
                book.nhapLieu();
            }
            book.muonSach();
        }
    }
}
