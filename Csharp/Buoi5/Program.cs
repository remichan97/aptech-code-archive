using System;
using System.Collections;

namespace Buoi5
{
	class Program
	{
		public class hocSinh
		{
			double diemtb, toan, ly, hoa;
			string hoTen;

			ArrayList std = new ArrayList();
			hocSinh student = new hocSinh();
			public void nhapLieu()
			{
				Console.WriteLine("Nhập họ tên học sinh: ");
				student.hoTen = Console.ReadLine();
				Console.WriteLine("Nhập điểm toán của học sinh");
				student.toan = Convert.ToDouble(Console.ReadLine());
				Console.WriteLine("Nhập điểm lý của học sinh");
				student.ly = Convert.ToDouble(Console.ReadLine());
				Console.WriteLine("Nhập điểm hóa của học sinh");
				student.hoa = Convert.ToDouble(Console.ReadLine());
				std.Add(student);
			}

			public void thongTin()
			{
				Console.WriteLine("Họ tên học sinh: ");
				Console.WriteLine("Điểm toán của học sinh: " + student.toan);
				Console.WriteLine("Điểm lý của học sinh: " + student.ly);
				Console.WriteLine("Điểm hóa của học sinh: " + student.hoa);
			}

			public double diemTB()
			{
				return (toan + ly + hoa) / 3;
			}

			public void sapXep() {
				std.Sort();
				thongTin();
			}
		}

		public static void Main(string[] args)
		{
			int n;
			hocSinh hs = new hocSinh();
			Console.WriteLine("Nhập số lượng học sinh muốn nhập: ");
			n = Convert.ToInt32(Console.ReadLine());
			for (int i = 1; i <= n; i++)
			{
				Console.WriteLine("Học sinh thứ " +i);
				hs.nhapLieu();
			}
			for (int i = 1; i <= n; i++)
			{
				Console.WriteLine("Thông tin của học sinh thứ " +i);
				hs.thongTin();
			}
			Console.WriteLine("Tính điểm trung bình của học sinh:");
			for (int i = 1; i <= n; i++)
			{
				Console.WriteLine("Điểm trung bình các môn của học sinh {0} là: {1}" ,i,hs.diemTB());
			}
			Console.WriteLine("Sắp xếp theo điểm trung bình");
			hs.sapXep();
		}
	}
}
