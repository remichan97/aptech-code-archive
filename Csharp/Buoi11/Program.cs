using System;
using cs = System.Console;

namespace Buoi11
{
	class Program
	{
		delegate void hienThi(string hoTen, string diaChi);

		static void Main(string[] args)
		{
			// collection collection = new collection();
			// collection.nhapLieu();
			// collection.inDanhSach();

			// DanhSach<int> ds = new DanhSach<int>(5);
			// ds.Nhap(3);
			// ds.Nhap(4);
			// ds.Nhap(5);
			// ds.Nhap(6);
			// ds.In();

			// hienThi obj = delegate(string hoTen, string diaChi) {
			//     Console.WriteLine("Xin chao ong "+hoTen);
			// };
			// obj += delegate (string hoTen, string diaChi) {
			//     Console.WriteLine("Dia chi "+diaChi);
			// };
			// obj("Nguyen Van A", "Ha Noi");
			int n;
			ThuVien thuVien = new ThuVien();
			do
			{
				cs.WriteLine("Nhập số lượng đầu sách cần thêm:");
                n = Convert.ToInt32(cs.ReadLine());
			} while (!(n > 0));
            for (int i = 1; i <= n; i++)
            {
                thuVien.nhapLieuSach();
            }
            thuVien.hienThiSach();
			do
			{
				cs.WriteLine("Nhập số lượng sinh viên cần thêm:");
                n = Convert.ToInt32(cs.ReadLine());
			} while (!(n <= 0));
            for (int i = 1; i <= n; i++)
            {
                thuVien.nhapLieuSinhVien();
            }
            thuVien.hienThiSinhVien();
            thuVien.choMuonSach();
            thuVien.danhSachMuonSach();
		}
	}
}