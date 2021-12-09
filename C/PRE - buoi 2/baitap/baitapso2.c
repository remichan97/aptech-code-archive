#include <stdio.h>

int main() {
	int a;
	do
	{
		printf("\nNhap mot so trong khoang tu 0 den 1000: ");
		scanf("%d",&a);
	} while (a<=0 || a>=1000);
	printf("\nHang tram cua so la: %d",a/100);
	printf("\nHang chuc cua so la: %d",(a%100)/10);
	printf("\nHang don vi cua so la: %d",(a%100)%10);
	return 0;
}