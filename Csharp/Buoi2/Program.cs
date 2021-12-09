using System;

namespace Buoi2
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.Write("Nhap vao ten cua ban: ");
			string ten = Console.ReadLine();
			Console.WriteLine("Xin chao ban " + ten);
			Console.WriteLine("Nhap vao so thu nhat:");
			int a = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine("Nhap vao so thu hai:");
			int b = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine("Nhap vao so thu ba:");
			int c = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine("So lon nhat trong cac so vua nhap la: " + Math.Max(Math.Max(a, b), c));
		}
	}
}
