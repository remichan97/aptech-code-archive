#include <stdio.h>
#include <string.h>

int main()
{
	int i, viTriCanChen = 4;
	char hoTen[30];
	printf("\nNhap ho ten: ");
	gets(hoTen);
	printf("\nSau khi nhap, ho ten la: %s", hoTen);
	int doDaiChuoiGoc = strlen(hoTen);
	for (i = strlen(hoTen); i > viTriCanChen; i--)
	{
		hoTen[i] = hoTen[i - 1];
	}
	hoTen[viTriCanChen] = '\n';
	hoTen[doDaiChuoiGoc + 1] = '\0';
	printf("\nSau khi them xuong dong, chuoi la: %s", hoTen);
	return 0;
}