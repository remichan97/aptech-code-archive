using System;

namespace Buoi4
{
	class Program
	{
		static int[] nhapLieu(int n)
		{
			int[] mang;
			mang = new int[n];
			for (int i = 0; i < mang.Length; i++)
			{
				Console.Write("Nhập phần tử thứ {0}: ", i + 1);
				mang[i] = Convert.ToInt32(Console.ReadLine());
			}
			return mang;
		}
		static int[] sapXepGiamDan(int[] mang)
		{
			int temp = 0;
			for (int i = 0; i < mang.Length; i++)
			{
				for (int j = i + 1; j < mang.Length; j++)
				{
					if (mang[i] < mang[j])
					{
						temp = mang[i];
						mang[i] = mang[j];
						mang[j] = temp;
					}
				}
			}
			return mang;
		}

		static int soLonNhat(int[] mang)
		{
			int max;
			Array.Sort(mang);
			max = mang[mang.Length - 1];
			return max;
		}

		static Boolean soNguyenTo(int a)
		{
			bool check = true;
			if (a < 2)
			{
				return false;
			}
			else
			{
				for (int i = 2; i < a; i++)
				{
					if (a % i == 0)
					{
						check = false;
					}
				}
			}
			return check;
		}
		static void Main(string[] args)
		{
			int n, lonNhat;
			int[] mang;
			Console.Write("Nhập số phần từ của mảng: ");
			n = Convert.ToInt32(Console.ReadLine());
			mang = nhapLieu(n);
			Console.WriteLine("Mảng đã sắp xếp giảm dần:");
			foreach (int item in sapXepGiamDan(mang))
			{
				Console.Write("{0} ", item);
			}
			lonNhat = soLonNhat(mang);
			Console.WriteLine("\nSố lớn nhất của mảng vừa nhập: " + lonNhat);
			Console.WriteLine("Các số nguyên tố trong mảng:");
			foreach (int item in mang)
			{
				if (soNguyenTo(item) == true)
				{
					Console.Write("{0} ", item);
				}
			}
		}
	}
}
