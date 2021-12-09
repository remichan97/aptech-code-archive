#include <stdio.h>
#include <math.h>

int i;
void menu()
{
	printf("\nMoi ban chon mot trong cac chuc nang sau:");
	printf("\n1. In cac so tu 1 den 100.");
	printf("\n2. In cac so tu 100 den 1.");
	printf("\n3. Tong cua 50 so 1, 2, 3,..., 50.");
	printf("\n4. Tinh tong 50 so chan bat dau tu 2.");
	printf("\n5. Tinh tong cua 20 so 5, 10, 15,..., 100.");
	printf("\n6. Tinh giai thua cua mot so bat ky.");
	printf("\n7. Kiem tra so nguyen to.");
	printf("\n8. In 10 so dau cua day Fibonacci va tim so thu 13 cua day day.");
	printf("\n9. Ket thuc chuong trinh.");
}

void daySoDen100()
{
	puts("\nDay so tu 1 den 100:");
	for (i = 1; i <= 100; i++)
	{
		printf("%d ", i);
	}
}

void daySo100Nguoc()
{
	puts("\nDay so tu 100 den 1:");
	for (i = 100; i >= 1; i--)
	{
		printf("%d ", i);
	}
}

void tinhTong50so()
{
	int tong = 0;
	for (i = 1; i <= 50; i++)
	{
		tong += i;
	}
	printf("\nTong cua 50 so 1, 2, 3,..., 50 la: %d", tong);
}

void tong50soBatDau2()
{
	int tong2 = 0;
	for (i = 2; i <= 100; i += 2)
	{
		tong2 += i;
	}
	printf("\nTong 50 so chan bat dau tu 2 la: %d", tong2);
}

void tinhTong20soCachDeu()
{
	int tongCachDeu = 0;
	for (i = 5; i <= 100; i += 5)
	{
		tongCachDeu += i;
	}
	printf("\nTong cua 20 so 5, 10, 15,..., 100 la: %d", tongCachDeu);
}

void giaiThua()
{
	int n, giaithua = 1;
	printf("\nNhap mot so de tinh gia thua: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		giaithua = giaithua * i;
	}
	printf("\nGia thua cua %d la: %d", n, giaithua);
}

void soNguyenTo()
{
	int a, dem = 0;
	printf("\nMoi ban nhap mot so de kien tra: ");
	scanf("%d", &a);
	if (a < 2)
	{
		printf("\n%d khong phai la so ngyen to.");
	}
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			dem++;
		}
	}
	if (dem != 0)
	{
		printf("\n%d khong phai la so nguyen to.", a);
	}
	else
	{
		printf("\n%d la so nguyen to.", a);
	}
}

void soThu13()
{
	int t1 = 0, t2 = 1, trungGian;
	for (i = 1; i < 13; i++)
	{
		trungGian = t1 + t2;
		t1 = t2;
		t2 = trungGian;
	}
	printf("\nSo thu 13 cua day Fibonacci la: %d", t1);
}

void fibonacci()
{
	int t1 = 0, t2 = 1, trungGian;
	printf("\nMuoi so dau tien cua day Fibonaci la: ");
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", t1);
		trungGian = t1 + t2;
		t1 = t2;
		t2 = trungGian;
	}
	soThu13();
}

int main()
{
	int option;
	while (1)
	{
		menu();
		do
		{
			printf("\nMoi ban nhap lua chon cua ban: ");
			scanf("%d", &option);
		} while (!(1 <= option && option <= 9));
		switch (option)
		{
		case 1:
			daySoDen100();
			break;
		case 2:
			daySo100Nguoc();
			break;
		case 3:
			tinhTong50so();
			break;
		case 4:
			tong50soBatDau2();
			break;
		case 5:
			tinhTong20soCachDeu();
			break;
		case 6:
			giaiThua();
			break;
		case 7:
			soNguyenTo();
			break;
		case 8:
			fibonacci();
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}