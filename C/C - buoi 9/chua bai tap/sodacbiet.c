#include <stdio.h>
#include <math.h>

float nhapN()
{
	float n;
	printf("\nNhap n: ");
	scanf("%f", &n);
	return n;
}

int soNguyen(float n)
{
	if (n == (int)n)
	{
		return 1;
	}
	return 0;
}

void tinhChanLe(float n)
{
	if (soNguyen(n) == 1)
	{
		if ((int)n % 2 == 0)
		{
			printf("\n%g la so chan.", n);
		}
		else
		{
			printf("\n%g la so le.", n);
		}
	}
	else
	{
		printf("\n%g khong chan, va khong le.", n);
	}
}

void tinhChanDuong(float n)
{
	if (soNguyen(n) == 1)
	{
		if ((int)n % 2 == 0 && n > 0)
		{
			printf("\n%g la so chan duong.", n);
		}
		else
		{
			printf("\n%g khong phai la so chan duong.", n);
		}
	}
}

void leAm(float n)
{
	if (soNguyen(n) == 1)
	{
		if ((int)n % 2 != 0 && n < 0)
		{
			printf("\n%g la so le am.", n);
		}
		else
		{
			printf("\n%g khong phai la so le am.", n);
		}
	}
	else
	{
		printf("\n%g khong phai la so le am", n);
	}
}

void chinhPhuong(float n)
{
	if (n > 0 && soNguyen(sqrt(n)) == 1)
	{
		printf("\n%g la so chinh phuong", n);
	}
	else
	{
		printf("\n%g khong phai la so chinh phuong", n);
	}
}

void dacBiet(float n)
{
	int donVi;
	int chuc;
	int tram;
	if (0 < n && n < 1000 && soNguyen(n) == 1)
	{
		donVi = (int)n % 10;
		chuc = (int)n / 10 % 10;
		tram = (int)n / 100 % 10;
		if (pow(donVi, 3) + pow(chuc, 3) + pow(tram, 3) == n)
		{
			printf("\n%g la so dac biet.", n);
		}
		else
		{
			printf("\n%g khong phai la so dac biet.", n);
		}
	}
	else
	{
		printf("\n%g khong phai la so dac biet.", n);
	}
}

int main()
{
	float n;
	n = nhapN();
	if (soNguyen(n) == 1)
	{
		printf("\n%g la so nguyen", n);
	}
	else
	{
		printf("\n%g khong phai la so nguyen.", n);
	}
	tinhChanLe(n);
	tinhChanDuong(n);
	leAm(n);
	chinhPhuong(n);
	dacBiet(n);
	return 0;
}