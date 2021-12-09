#include <stdio.h>

int main()
{
	char ten[50];
	char msv[20];
	int namsinh;
	char lophoc[10];
	char chuyennganh[40];
	/*yêu cầu nhập dữ liệu*/
	printf("\nMoi ban nhap ma sinh vien: ");
	gets(msv);
	printf("\nBan ten gi? ");
	gets(ten);
	printf("\nBan dang hoc lop nao? ");
	gets(lophoc);
	printf("\nChuyen nganh ban mong muon la gi? ");
	gets(chuyennganh);
	printf("\nBan sinh nam bao nhieu? ");
	scanf("%d", &namsinh);
	/*kết quả đầu ra*/
	printf("\nTen cua ban la %s", ten);
	printf("\nMa sinh vien la %s", msv);
	printf("\nBan sinh nam %d", namsinh);
	printf("\nHien dang hoc lop %s", lophoc);
	printf("\nChuyen nganh mong muon cua ban la: %s", chuyennganh);
	return 0;
	/*kết thúc chương trình*/
}