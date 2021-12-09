#include <stdio.h>
#include <math.h>
int main()
{
	printf("\n1.Nhap vao so nguyen N");
	printf("\n2.Nhap mot mang gom N so thuc");
	printf("\n3.Tim so lon nhat trong mang");
	printf("\n4.Tim so nho nhat trong mang");
	printf("\n5.Tim so nguyen duong chan lon nhat trong mang");
	printf("\n6.Tim so am le nho nhat trong mang ");
	printf("\n7.Tim so chinh phuong trong mang");
	printf("\n8.Ting tong cac mang");
	printf("\n9.Tinh trung binh cong cac phan tu trong mang");
	printf("\n10.Tim nhung phan tu lon hon trung binh cong");
	printf("\n11.Sap xep mang theo trat tu tang dan");
	printf("\n12.Sap xep mang theo trat tu tang dan");
	printf("\n13.Thoat");
	int option;
	while (1)
	{
		printf("\n-------Moi ban chon chuong trinh: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("\n+++Nhap vao so nguyen N+++\n");
			int N;
			do
			{
				printf("\nMoi ban nhap so nguyen N = ");
				scanf("%d", &N);
			} while (0 > N || N > 50);
			break;
		case 2:
			printf("\n+++Nhap mot mang gom N so thuc+++\n");
			int i, mang[49];
			for (i = 0; i < N; i++)
			{
				printf("\nSo phan tu [%d] =", i + 1);
				scanf("%d", &mang[i]);
			}
			break;
		case 3:
			printf("/n+++Tim so lon nhat trong mang+++\n");
			int max;
			max = mang[0];
			for (i = 1; i < N; i++)
			{
				if (max < mang[i])
				{
					max = mang[i];
				}
			}
			printf("\nmax=%d", max);
			break;
		case 4:
			printf("/n+++Tim so nho nhat trong mang+++\n");
			int min;
			min = mang[0];
			for (i = 1; i < N; i++)
			{
				if (min > mang[i])
				{
					min = mang[i];
				}
			}
			printf("\nmin=%d", min);
			break;
		case 5:
			printf("\n+++Tim so nguyen duong chan lon nhat trong mang+++\n");
			int maxchan;
			maxchan = mang[0];
			for (i = 1; i < N; i++)
			{
				if (mang[i] > 0 && ((int)mang[i] % 2 == 0) && (maxchan < mang[i]))
				{
					maxchan = mang[i];
				}
			}
			printf("\nmaxchan=%d", maxchan);
			break;
		case 6:
			printf("\n+++Tim so am le nho nhat trong mang +++\n");
			int minle;
			minle = mang[0];
			for (i = 1; i < N; i++)
			{
				if (((int)mang[i] % 2 != 0) && mang[i] < 0 && minle > mang[i])
				{
					minle = mang[i];
				}
				else
				{
					printf("\nKhong co so am le nho nhat nao");
					break;
				}
			}
			printf("\nminle=%d", minle);
			break;
		case 7:
			printf("\n+++Tim so chinh phuong trong mang+++\n");
			int scp;
			scp = sqrt(mang[i]);
			for (i = 0; i < N; i++)
			{
				if ((scp * scp) == mang[i])
				{
				}
				else
				{
					printf("\nKhong co so chinh phuong nao");
				}
				printf("%d", scp);
			}
			break;
		case 8:
			printf("\n+++Ting tong cac mang+++\n");
			int tong = 0;
			for (i = 0; i < N; i++)
			{
				tong += mang[i];
			}
			printf("tong mang = %d", tong);
			break;
		case 9:
			printf("\n+++Tinh trung binh cong cac phan tu trong mang+++\n");
			float tbc = 0;
			tong = 0;
			for (i = 0; i < N; i++)
			{
				tbc = (tong += mang[i]) / N;
			}
			printf("TBC = %g", tbc);
			break;
		case 10:
			printf("\n+++Tim nhung phan tu lon hon trung binh cong+++\n");
			printf("\nCac phan tu lon hon TBC la ");
			int pt = mang[0];
			for (i = 0; i < N; i++)
			{
				if (mang[i] > tbc)
				{
					pt = mang[i];
					printf(" %d ", pt);
				}
			}
			break;
		case 11:
			printf("\n+++Sap xep mang theo trat tu tang dan+++\n");
			int j, tg;
			for (i = 0; i < N - 1; i++)
			{
				for (j = i + 1; j < N; j++)
				{
					if (mang[i] > mang[j])
					{
						tg = mang[i];
						mang[i] = mang[j];
						mang[j] = tg;
					}
				}
			}
			for (i = 0; i < N; i++)
			{
				printf(" %d ", mang[i]);
			}
			break;
		case 12:
			printf("\n+++Sap xep mang theo trat tu tang dan+++\n");
			int gd;
			for (i = 0; i < N - 1; i++)
			{
				for (j = i + 1; j < N; j++)
				{
					if (mang[i] < mang[j])
					{
						gd = mang[i];
						mang[i] = mang[j];
						mang[j] = gd;
					}
				}
			}
			for (i = 0; i < N; i++)
			{
				printf(" %d ", mang[i]);
			}
			break;

		case 13:
			return 0;
		}
	}
}
