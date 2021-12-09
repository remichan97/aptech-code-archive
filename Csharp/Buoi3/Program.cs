using System;

namespace Buoi3
{
	class Program
	{
		static void ptBacNhat()
		{
			Console.WriteLine("Giải phương trình bậc nhất (ax+b = c):");
			Console.WriteLine("Nhập hệ số thứ nhất:");
			int a = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine("Nhập hệ số thứ hai:");
			int b = Convert.ToInt32(Console.ReadLine());
			if (a == 0)
			{
				if (b == 0)
				{
					Console.WriteLine("Phương trình vô số nghiệm");
				}
				else
				{
					Console.WriteLine("Phương trình vô nghiệm");
				}
			}
			else
			{
				double c = -(b / a);
				Console.WriteLine("Phương trình có nghiệm: " + c);
			}
		}

		static void ptBacHai()
		{
			Console.WriteLine("Giải phương trình bậc hai (ax^2+bx+c = 0): ");
			Console.WriteLine("Nhập hệ số thứ nhất:");
			double a = Convert.ToDouble(Console.ReadLine());
			Console.WriteLine("Nhập hệ số thứ hai:");
			double b = Convert.ToDouble(Console.ReadLine());
			Console.WriteLine("Nhập hệ số thứ ba:");
			double c = Convert.ToDouble(Console.ReadLine());
			if (a == 0)
			{
				if (b == 0)
				{
					Console.WriteLine("Phương trình vô nghiệm");
				}
				else
				{
					Console.WriteLine("Phương trình có nghiệm: " + (-b / a));
				}
				return;
			}
			else
			{
				double delta = Math.Pow(b, 2) - 4 * a * c;
				if (delta < 0)
				{
					Console.WriteLine("Phương trình vô nghiệm");
				}
				else if (delta == 0)
				{
					Console.WriteLine("Phương trình có nghiệm kép:");
					Console.WriteLine("x1 = x2 = " + (-b / 2 * a));
				}
				else
				{
					Console.WriteLine("Phương trình có hai nghiệm phân biệt:");
					Console.WriteLine("x1 = " + (-(b + Math.Sqrt(delta)) * 2 * a));
					Console.WriteLine("x2 = " + (-(b - Math.Sqrt(delta)) * 2 * a));

				}
			}
		}

		static int giaiThua(int a)
		{
			int r = 1;
			for (int i = 1; i <= a; i++)
			{
				r = r * i;
			}
			return r;
		}

		static int tongGiaiThua(int b)
		{
			int tong = 0;
			for (int i = 1; i <= b; i++)
			{
				tong += giaiThua(i);
			}
			return tong;
		}
		static void Main(string[] args)
		{
			int a, b;
			ptBacNhat();
			ptBacHai();
			do
			{
				Console.WriteLine("Nhập một số nguyên bất kỳ > 0 để tính gia thừa: ");
				a = Convert.ToInt32(Console.ReadLine());
			} while (a < 0);
			Console.WriteLine("Giai thừa của {0} là: {1}", a, giaiThua(a));
			do
			{
				Console.WriteLine("Nhập một số nguyên bất kỳ > 0 để tính tổng gia thừa: ");
				b = Convert.ToInt32(Console.ReadLine());
			} while (b < 0);
			Console.WriteLine("Tổng giai thừa của {0} là: {1}", b, tongGiaiThua(b));
		}
	}

}