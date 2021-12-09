#include <stdio.h>

void nhapLieu(float *pnumber1, float *pnumber2)
{
	printf("\nNhap he so a: ");
	scanf("%f", pnumber1);
	printf("\nNhap he so b: ");
	scanf("%f", pnumber2);
}

void tinhTong(float number1, float number2)
{
	double tong;
	tong = number1 + number2;
	printf("\nTong 2 so la: %g", tong);
}

void tinhHieu(float number1, float number2)
{
	double hieu;
	hieu = number1 - number2;
	printf("\nHieu cua hai so la: %g", hieu);
}

void tinhNhan(float number1, float number2)
{
	double tich;
	tich = number1 * number2;
	printf("\nTich cua hai so la: %g", tich);
}

void tinhChia(float number1, float number2)
{
	double thuong;
	thuong = number1 / number2;
	printf("\nThuong cua hai so la: %g", thuong);
}

void uocSoChungLonNhat(float number1, float number2) {
	int i;
	float uocSo;
	for (i = 1; i <= number1 || i <= number2; i++)
	{
		if ((int)number1%i == 0 && (int)number2%i == 0)
		{
			uocSo = i;
		}
	}
	printf("\nUoc so chung lon nhat cua hai so la: %g", uocSo);
}

void boiSoChungNhoNhat(float number1, float number2) {
	float boiSo, step, max;
	if (number1 > number2)
	{
		max = step = number1;
	}
	else
	{
		max = step = number2;
	}
	while (1)
	{
		if ((int)max%(int)number1 == 0 && (int)max%(int)number2 == 0)
		{
			boiSo = max;
			break;
		}
		max += step;
	}
	printf("\nBoi so chung nho nhat cua hai so la: %g", boiSo);
}

int main()
{
	float number1, number2, *pnumber1, *pnumber2;
	pnumber1 = &number1;
	pnumber2 = &number2;
	nhapLieu(pnumber1, pnumber2);
	tinhTong(number1, number2);
	tinhHieu(number1, number2);
	tinhNhan(number1, number2);
	tinhChia(number1, number2);
	uocSoChungLonNhat(number1, number2);
	boiSoChungNhoNhat(number1, number2);
	return 0;
}