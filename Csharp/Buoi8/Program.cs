using System;

namespace Buoi8
{
    class Program
    {
        static void Main(string[] args)
        {
            Sach book = new Sach();
            book.nhapSach();
            HocSinh std = new HocSinh();
            std.themHocSinh();
            MuonSach br = new MuonSach();
            br.muonSach();
            
        }
    }
}
