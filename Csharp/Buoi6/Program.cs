using System;

namespace Buoi6
{
	class Program
	{
		static void Main(string[] args)
		{
            Console.WriteLine("Hình vuông:");
			hinhVuong hv = new hinhVuong();
			Console.Write("\nNhập cạnh của hình vuông: ");
            hv.chieuDai = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Diện tích hình vuông: "+hv.dienTich(hv.chieuDai));
            Console.WriteLine("==============");
            Console.WriteLine("Hình chữ nhật:");
            hinhChuNhat chuNhat = new hinhChuNhat();
            Console.WriteLine("Nhập chiều dài:");
            chuNhat.chieuDai = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Nhập chiều rộng:");
            chuNhat.chieuRong = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Chu vi: " +chuNhat.chuVi(chuNhat.chieuDai, chuNhat.chieuRong));
            Console.WriteLine("Diện tích: " +chuNhat.dienTich(chuNhat.chieuDai, chuNhat.chieuRong));
            Console.WriteLine("=================");
            Console.WriteLine("Tam giác");
            tamGiac tri = new tamGiac();
            Console.Write("Nhập cạnh thứ nhất của tam giác: ");
            tri.a = Convert.ToDouble(Console.ReadLine());
            Console.Write("Nhập cạnh thứ hai của tam giác: ");
            tri.b = Convert.ToDouble(Console.ReadLine());
            Console.Write("Nhập cạnh thứ ba của tam giác: ");
            tri.c = Convert.ToDouble(Console.ReadLine());
            if (tri.a < tri.b + tri.c && tri.b < tri.c+tri.a && tri.c < tri.a+tri.b)
            {
                Console.WriteLine("Chu vi tam giác: " +tri.chuVi(tri.a, tri.b, tri.c));
                Console.WriteLine("Diẹn tích tam giác: "+tri.dienTich(tri.a, tri.b, tri.c));
            }
            else
            {
                Console.WriteLine("Ba cạnh đã nhập không tạo thành tam giác");
            }
		}
	}
}
