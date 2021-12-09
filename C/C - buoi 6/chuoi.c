#include <stdio.h>
#include <string.h>

int main()
{
	//Chuỗi (String): thực chất, C không có chuỗi, chuỗi ở đây được hiểu là một mảng ký tự 1 chiều, kết thúc bởi ký tự '\0' hay là NULL.
	//Khai báo chuỗi:
	//char tên_chuỗi[kích_thước];
	//ví dụ:
	char hoTen[30];
	///lưu ý: không được phép gán trực tiếp giá trị cho mảng: hoTen = "Truong Vu Binh" là không được phép.
	//Nhập chuỗi:
	printf("\nMoi nhap 1 chuoi: ");
	gets(hoTen);
	puts(hoTen); //hiển thị chuỗi
	printf("\nSau khi nhap chuoi: %s", hoTen);
	//Xử lý chuỗi:
	//Lấy kích thước chuỗi: strlen(chuỗi);
	printf("\nKich thuoc chuoi: %d", strlen(hoTen));
	//Copy (gán - lưu) nội dung chuỗi:
	strcpy(hoTen, "Truong Vu Binh");
	puts("");
	puts(hoTen);
	//Nối chuỗi (curently having a runtime error):
	///strcpy(hoTen, strcat("ABCD", "1234"));
	//puts(hoTen);
	//Đảo ngược chuỗi:
	strrev(hoTen);
	puts(hoTen);
	//Tìm ký tự trong chuỗi: Nếu tìm thấy trả về chuỗi, ngược lại thì trả về NULL
	printf("\n%s" ,strchr(hoTen, 'u'));
	//Tìm chuỗi trong chuỗi: Nếu tìm thấy trả về chuỗi, ngược lại trả về NULL
	printf("\n%s", strstr(hoTen, "n"));
	//So sánh hai chuỗi S1, S2: So sánh theo thử tự ký tụ trong bảng mã ASCII. Việc so sánh bắt đầu từ bên trái của 2 chuỗi. Cụ thể hàm sẽ lấy từng cặp ký tự của hai chuỗi từ bên trái đem so sánh, nếu khác nhau thì việc so sánh lập tức dừng lại và đưa ra kết luận: Ký tự nào lớn hơn thì chuỗi tương ứng sẽ lớn hơn.
	//strcmp(S1,S2): Trả về số > 0 nếu S1 > S2, ==0 nếu hai biến giống nhau, < 0 nếu S1 < S2. Ví dụ:
	printf("\n%d", strcmp("abc1234", "acd")); //Thuong < Vu
	/*Các ký tự đặc biêt:
	Tab: '\t'
	Enter: '\n'
	Ký tự \: '\\'
	Ký tự ": '\"'
	Ký tự %: '\%'*/
	
	return 0;
}