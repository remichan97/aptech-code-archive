#include <stdio.h>
#include <string.h>

///Tạo 1 kiểu đại diện cho sách:
typedef struct
{
    char bookName[50];
    char author[30];
    int pages;
    int edition;
    float price;
} Book;

Book nhapSach()
{
    Book sach;
    printf("\nNhap ten sach: ");
    gets(sach.bookName);
    printf("\nNhap tac gia: ");
    gets(sach.author);
    printf("\nNhap so trang sach: ");
    scanf("%d", &sach.pages);
    printf("\nNhap so lan tai ban: ");
    scanf("%d", &sach.edition);
    printf("\nNhap gia sach: ");
    scanf("%f", &sach.price);
    fflush(stdin);
    return sach;
}

void inThongTinSach(Book sach)
{
    printf("\nTen sach: %s", sach.bookName);
    printf("\nTac gia: %s", sach.author);
    printf("\nSo trang: %d", sach.pages);
    printf("\nSo lan tai ban: %d", sach.edition);
    printf("\nGia ban: %g", sach.price);
}

void nhapCacSach(Book cacSach[], int soLuongSach)
{
    int i;
    for (i = 0; i < soLuongSach; i++)
    {
        printf("\nQuyen sach thu %d:", i + 1);
        cacSach[i] = nhapSach();
    }
}

void inCacQuyenSach(Book cacSach[], int soLuongSach)
{
    int i;
    for (i = 0; i < soLuongSach; i++)
    {
        printf("\nQuyen sach thu %d:", i + 1);
        inThongTinSach(cacSach[i]);
    }
}

void timSachTheoTen(Book cacSach[], int soLuongSach)
{
    char tenSach[50];
    printf("\nMoi ban nhap ten sach muon tim: ");
    fflush(stdin);
    gets(tenSach);
    int timThay = 0;
    int i;
    for (i = 0; i < soLuongSach; i++)
    {
        if (strcmp(cacSach[i].bookName, tenSach) == 0)
        {
            inThongTinSach(cacSach[i]);
            timThay = 1;
            break;
        }
    }
    if (!timThay)
    {
        printf("\nKhong tim thay cuon sach nao co ten: %s", tenSach);
    }
}

void sapXepTheoTenSach(Book cacSach[], int soLuongSach)
{
    int i, j;
    Book tg;
    ///Sắp xếp tăng:
    for (i = 0; i < soLuongSach - 1; i++)
    {
        for (j = i + 1; j < soLuongSach; j++)
        {
            if (strcmp(cacSach[i].bookName, cacSach[j].bookName) > 0)
            {
                tg = cacSach[i];
                cacSach[i] = cacSach[j];
                cacSach[j] = tg;
            }
        }
    }
    printf("\nSau khi sap xep tang dan, ta duoc:");
    inCacQuyenSach(cacSach, soLuongSach);
}

int main()
{

    ///Struct (Cấu trúc): Cho phép tạo kiểu dữ liệu mới
    ///bao hàm nhiều thông tin hơn, mô tả được đối tượng
    ///thực tế hơn.
    ///*Tạo Struct:
    ///typedef struct{
    ///khai báo các biến chứa thông tin
    ///}tên_kiểu_mới;
    ///*Tạo đối tượng:
    ///tên_kiểu_mới tên_đối_tượng;
    //Book lapTrinhC;
    //lapTrinhC=nhapSach();
    //inThongTinSach(lapTrinhC);
    ///*Truy cập các thành phần của đối tượng:
    ///Dùng toán tử (.)
    ///Ví dụ:
    //lapTrinhC.price=40000;//set
    //printf("\n%g",lapTrinhC.price);//get
    int soLuongSach = 2;
    Book sachLapTrinh[soLuongSach];
    nhapCacSach(sachLapTrinh, soLuongSach);
    inCacQuyenSach(sachLapTrinh, soLuongSach);
    timSachTheoTen(sachLapTrinh, soLuongSach);
    sapXepTheoTenSach(sachLapTrinh, soLuongSach);

    return 0;
}