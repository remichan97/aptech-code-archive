#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu()
{
	printf("\nMoi ban chon mot trong cac chuc nang sau: ");
	printf("\n1. Nhap mot so nguyen trong khoang 0 < n < 50.");
	printf("\n2. Nhap mot mang gom n so thuc.");
	printf("\n3. Tim so lon nhat trong mang vua nhap.");
	printf("\n4. Tim so nho nhat trong mang vua nhap.");
	printf("\n5. Tim so duong chan lon nhat trong mang vua nhap.");
	printf("\n6. Tim so am le nho nhat trong mang vua nhap.");
	printf("\n7. Tim cac so chinh phuong trong mang vua nhap.");
	printf("\n8. Tinh tong cua mang.");
	printf("\n9. Tinh trung binh cong cac phan tu cua mang.");
	printf("\n10. Tim nhung phan tu lon hon trung binh cong trong mang.");
	printf("\n11. Sap xep mang theo thu tu tang dan.");
	printf("\n12. Sap xep mang theo thu tu giam dan.");
	printf("\n13. Ket thuc chuong trinh.");
}

void nhapN(int *n)
{
	printf("\n===Nhap so nguyen===");
	do
	{
		printf("\nNhap mot so nguyen trong khoang 0 < n < 50: ");
		scanf("%d", &*n);
	} while (!(0 < *n && *n < 50));
}

int main()
{
	int option, n, i, j, xacNhan, mot, tinhAVG;
	float *mang, max, min, maxChan, minLe, tong, chinhPhuong, tbCong, avg, lonHonAVG, tg;
	while (1)
	{
		menu();
		do
		{
			printf("\nMoi nhap lua chon cua ban: ");
			scanf("%d", &option);
		} while (!(1 <= option && option <= 13));
		switch (option)
		{
		case 1:
			mot = 1;
			nhapN(&n);
			break;
		case 2:
			printf("\n===Nhap du lieu cho mang===");
			if (mot != 1)
			{
				printf("\nChua nhap gioi han mang, vui long chon 1 de nhap gioi han.");
				continue;
			}
			else
			{
				xacNhan = 1;
				mang = (float *)malloc(n * sizeof(float));
				printf("\nMoi nhap du lieu cho mang:");
				for (i = 0; i < n; i++)
				{
					printf("\nDu lieu thu %d: ", i + 1);
					scanf("%f", mang + i);
				}
			}
			break;
		case 3:
			printf("\n===Tim so lon nhat===");
			if ((mot != 1 && xacNhan != 1))
			{
				printf("\nChua co du lieu de xu ly, vui long nhap du lieu truoc.");
				continue;
			}
			else
			{
				max = mang[0];
				for (i = 0; i < n; i++)
				{
					if (max < mang[i])
					{
						max = mang[i];
					}
				}
				printf("\nSo lon nhat cua mang la: %g", max);
			}
			break;
		case 4:
			printf("\n===Tim so nho nhat===");
			if ((mot != 1 && xacNhan != 1))
			{
				printf("\nChua co du lieu de xu ly, vui long nhap du lieu truoc.");
				continue;
			}
			else
			{
				min = mang[0];
				for (i = 0; i < n; i++)
				{
					if (min > mang[i])
					{
						min = mang[i];
					}
				}
			}
			printf("\nSo nho nhat trong mang la: %g", min);
			break;
		case 5:
			printf("\n===Tim so duong chan lon nhat===");
			if (mot != 1 && xacNhan != 1)
			{
				printf("\nChua co du lieu de xu ly, vui long nhap du lieu truoc.");
				continue;
			}
			else
			{
				maxChan = mang[0];
				for (i = 0; i < n; i++)
				{
					if (mang[i] > 0 && (int)mang[i] % 2 == 0 && maxChan < mang[i])
					{
						maxChan = mang[i];
					}
				}
				printf("\nSo duong chan lon nhat trong mang la: %g", maxChan);
			}
			break;
		case 6:
			printf("\n===Tim so am le nho nhat===");
			if (mot != 1 && xacNhan != 1)
			{
				printf("\nChua co du lieu de xu ly, vui long nhap du lieu truoc.");
				continue;
			}
			else
			{
				minLe = mang[0];
				if (mang[i] < 0 && minLe > mang[i] && (int)mang[i] % 2 != 0)
				{
					minLe = mang[i];
					printf("\nSo am le nho nhat la: %g", minLe);
				}
				else
				{
					printf("\nKhong co so nao thoa man.");
				}
			}
			break;
		case 7:
			printf("\n===Tim so chinh phuong===");
			if (mot != 1 && xacNhan != 1)
			{
				printf("\nChua co du lieu de xu ly, vui long nhap du lieu truoc.");
				continue;
			}
			else
			{
				for (i = 0; i < n; i++)
				{
					if ((int)mang[i] > 0 && (sqrt(mang[i]) == (int)sqrt(mang[i])))
					{
						chinhPhuong = mang[i];
					}
					else
					{
						printf("\nMang nay khong co so chinh phuong nao.");
						break;
					}
					printf("\nCac so chinh phuong trong mang la: %g", chinhPhuong);
				}
			}
			break;
		case 8:
			printf("\n===Tinh tong===");
			if (mot != 1 && xacNhan != 1)
			{
				printf("\nChua co du lieu de xu ly, vui long nhap du lieu truoc.");
				continue;
			}
			else
			{
				tong = 0;
				for (i = 0; i < n; i++)
				{
					tong += mang[i];
				}
				printf("\nTong cac so trong mang la: %g", tong);
			}
			break;
		case 9:
			printf("\n===Tinh trung binh cong===");
			if (mot != 1 && xacNhan != 1)
			{
				printf("\nChua co du lieu de xu ly, vui long nhap du lieu truoc.");
				continue;
			}
			else
			{
				tinhAVG = 1;
				tbCong = 0;
				for (i = 0; i < n; i++)
				{
					tbCong += mang[i];
				}
				avg = tbCong / n;
				printf("\nTrung binh cong cua cac so trong mang la: %g", avg);
			}
			break;
		case 10:
			printf("\n===Tim so lon hon trung binh cong===");
			if (mot != 1 && xacNhan != 1 && tinhAVG != 1)
			{
				printf("\nChua co du lieu de xu ly, vui long nhap du lieu truoc.");
				continue;
			}
			else
			{
				for (i = 0; i < n; i++)
				{
					if (avg < mang[i])
					{
						lonHonAVG = mang[i];
						printf("\nSo lon hon trung binh cong cua mang la: %g", lonHonAVG);
					}
				}
			}
			break;
		case 11:
			printf("\n===Sap xep tang dan===");
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if (mang[i] > mang[j])
					{
						tg = mang[i];
						mang[i] = mang[j];
						mang[j] = tg;
					}
				}
			}
			printf("\nMang da sap xep tang dan la: ");
			for (i = 0; i < n; i++)
			{
				printf("%g ", mang[i]);
			}
			break;
		case 12:
			printf("\n===Sap xep giam dan===");
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if (mang[i] < mang[j])
					{
						tg = mang[i];
						mang[i] = mang[j];
						mang[j] = tg;
					}
				}
			}
			printf("\nMang da sap xep giam dan la: ");
			for (i = 0; i < n; i++)
			{
				printf("%g ", mang[i]);
			}
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}