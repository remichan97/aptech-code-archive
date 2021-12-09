using System;
using cs = System.Console;
using System.Collections.Generic;

namespace Buoi8
{

	public class Sach
	{
		public int idSach = 0;

		public string tenSach { get; set; }

		public int soLuong { get; set; }

		public string muon {get;set;}

		public void nhapSach()
		{
			idSach += 1;
			Console.WriteLine("Nhập tên sách");
			tenSach = Console.ReadLine();
			Console.WriteLine("Nhập số lượng");
			soLuong = Convert.ToInt32(Console.ReadLine());
		}
	}

	public class HocSinh
	{
		public int id { get; set; }
		public string ten { get; set; }

		public void themHocSinh()
		{
			id += 1;
			Console.WriteLine("Nhập tên học sinh:");
			ten = Console.ReadLine();
		}
	}

	public class MuonSach : Sach
	{
		public void muonSach() {
			Console.WriteLine("Nhập tên sách muốn mượn:");
			muon = Console.ReadLine();
			if (String.Equals(muon, tenSach))
			{
				soLuong -= 1;
				Console.WriteLine("Đã mượn được sách");
			}
			else
			{
				Console.WriteLine("Không tìm thấy sách được nhập");
			}
		}
	}

}