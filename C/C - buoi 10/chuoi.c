#include <stdio.h>
#include <string.h>

int main()
{

	///Chuỗi (String): Là một tập hợp các ký tự liên
	///tục nhau, được đặt trong cặp nháy kép "".
	///Kết thúc chuỗi là ký tự '\0', ký tự này trình
	///dịch sẽ tự động thêm vào cuối chuỗi.
	///Ngôn ngữ lập trình C không có kiểu chuỗi, nên
	///phải dùng mảng ký tự 1 chiều.
	///Khai báo chuỗi:
	///char tên_chuỗi[size];
	///Ví dụ:
	char hoTen[30];
	char diaChi[100]; ///Enter: '\n'
	///Tab: '\t'
	///Ký tự \: '\\'
	///Ký tự ": '\"'
	///Ký tự %: '%%'
	printf("\nKy tu nhay kep la: \"");
	///*Nhập liệu cho chuỗi: dùng hàm gets().
	///Ví dụ:
	printf("\nMoi nhap ho ten: ");
	gets(hoTen);
	printf("\nSau khi nhap, ho ten la: %s", hoTen);
	///hoTen[3]='\n';
	///printf("\nSau khi update, ho ten la: %s",hoTen);
	int i;
	int viTriCanChen = 4;
	int doDaiChuoiGoc = strlen(hoTen);
	for (i = strlen(hoTen); i > viTriCanChen; i--)
	{
		hoTen[i] = hoTen[i - 1];
	}
	hoTen[viTriCanChen] = '\n';
	printf("\nChieu dai chuoi=%d", strlen(hoTen));
	hoTen[doDaiChuoiGoc + 1] = '\0';
	printf("\nSau khi chen xuong dong, chuoi la: %s", hoTen);
	printf("\nChieu dai chuoi=%d", strlen(hoTen));
	return 0;
}