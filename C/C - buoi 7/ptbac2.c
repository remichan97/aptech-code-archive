#include <stdio.h>

float nhapA()
{
	float a;
	printf("\nNhap he so a: ");
	scanf("%f", &a);
	return a;
}
float nhapB()
{
	float b;
	printf("\nNhap he so a: ");
	scanf("%f", &b);
	return b;
}
float nhapC()
{
	float c;
	printf("\nNhap he so a: ");
	scanf("%f", &c);
	return c;
}
double tinhDelta(float a, float b, float c)
{
	double delta;
	delta = b * b - 4 * a * c;
	return delta;
}
void xacDinhNghiem(float a, float b, float c)
{
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("\nVo so nghiem.");
			}
			else
			{
				printf("\nVo nghiem.");
			}
		}
		else
		{
			printf("\nPT co nghiem kep x1 = x2 = %g", -b / (2 * a));
		}
	}
	else
	{
		double d = tinhDelta(a, b, c);
		if (d < 0)
		{
			printf("\nPT vo nghiem");
		}
		else if (d == 0)
		{
			printf("\nPT co nghiem kep, x1=x2=%g", -b / (2 * a));
		}
		else
		{
			printf("\nPT co 2 nghiem phan biet:");
			printf("\nx1=%g", (-b + sqrt(d)) / (2 * a));
			printf("\nx1=%g", (-b - sqrt(d)) / (2 * a));
		}
	}
}

int main()
{

	///Giải phương trình bấc 2 bằng cách tách chương trình thành các hàm riêng biệt:
	//Nhập các hệ số a, b, c
	//Tính Delta
	//Xác định nghiệm.
	float a, b, c;
	a = nhapA();
	b = nhapB();
	c = nhapC();
	tinhDelta(a, b, c);
	xacDinhNghiem(a, b, c);
	return 0;
}
