#include <stdio.h>
#include <math.h>

float nhapLieu()
{
	float n;
	printf("\nNhap mot so bat ky: ");
	scanf("%f", &n);
	return n;
}

void kiemTraSoNguyen(float n)
{
	if (n == (int)n)
	{
		printf("\n%g la so nguyen.", n);
	}
	else
	{
		printf("\n%g khong phai la so nguyen", n);
	}
}

void chanLe(float n)
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

void chanDuong(float n)
{
	if ((int)n % 2 == 0 && n > 0)
	{
		printf("\n%g la so chan duong", n);
	}
	else
	{
		printf("\n%g khong phai la so chan duong.", n);
	}
}

void leAm(float n)
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

void chinhPhuong(float n)
{
	if (n > 0 && sqrt(n) == (int)sqrt(n))
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
	int donvi, chuc, tram;
	if (0 < n && n < 1000)
	{
		donvi = (int)n % 10;
		chuc = (int)n / 10 % 10;
		tram = (int)n / 100 % 10;
		if (n == (pow(donvi, 3) + pow(chuc, 3) + pow(tram, 3)))
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
	n = nhapLieu();
	printf("\n===Kiem tra so nguyen===");
	kiemTraSoNguyen(n);
	printf("\n===Kiem tra tinh chan le===");
	chanLe(n);
	printf("\n===Kiem tra so chan duong===");
	chanDuong(n);
	printf("\n===Kiem tra so le am===");
	leAm(n);
	printf("\n===Kiem tra so chinh phuong===");
	chinhPhuong(n);
	printf("\n===Kiem tra so dac biet===");
	dacBiet(n);
	return 0;
}