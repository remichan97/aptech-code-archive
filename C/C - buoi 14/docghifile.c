#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char ten[30];
	char tacGia[30];
	char theLoai[30];
	float dai;
	float rong;
	float gia;
} Picture;

void menu()
{
	printf("\n1.");
	printf("\n2.");
	printf("\n3.");
	printf("\n4.");
	printf("\n5.");
	printf("\n6.");
	printf("\n7.");
	printf("\n8.");
}

int nhapSoLuongTranh()
{
	int n;
	do
	{
		printf("\nMoi nhap so luong tranh: ");
		scanf("%d", &n);
	} while (!(0 < n && n <= 10));
	return n;
}

void nhapThongTinTranh(Picture pic[], int soBucTranh)
{
	int i;
	printf("\nMoi nhap thong tin cho tung tranh:");
	for (i = 0; i < soBucTranh; i++)
	{
		fflush(stdin);
		printf("\nBuc tranh thu %d:", i + 1);
		do
		{
			printf("\nNhap ten tranh: ");
			gets(pic[i].ten);
		} while (strlen(pic[i].ten) == 0);
		do
		{
			printf("\nNhap ten tac gia: ");
			gets(pic[i].tacGia);
		} while (strlen(pic[i].tacGia) == 0);
		do
		{
			printf("\nNhap the loai tranh: ");
			gets(pic[i].theLoai);
		} while (strlen(pic[i].theLoai) == 0);
		do
		{
			printf("\nNhap chieu dai tranh: ");
			scanf("%f", &pic[i].dai);
		} while (pic[i].dai <= 0);
		do
		{
			printf("\nNhap chieu rong tranh: ");
			scanf("%f", &pic[i].rong);
		} while (pic[i].rong <= 0);
		do
		{
			printf("\nNhap gia tranh: ");
			scanf("%f", &pic[i].gia);
		} while (pic[i].gia <= 0);
	}
}

void hienThiTranh(Picture pic)
{
	printf("\nTen tranh: %s", pic.ten);
	printf("\nTac gia: %s", pic.tacGia);
	printf("\nThe loai: %s", pic.theLoai);
	printf("\nChieu dai: %g", pic.dai);
	printf("\nChieu rong: %g", pic.rong);
	printf("\nGia ban: %g", pic.gia);
}

void hienThiThongTinCacTranh(Picture pic[], int soBucTranh)
{
	printf("\nThong tin du lieu tranh:");
	int i;
	for (i = 0; i < soBucTranh; i++)
	{
		printf("\nBuc tranh thu %d:", i + 1);
		hienThiTranh(pic[i]);
	}
}

void hoanViTranh(Picture *pic1, Picture *pic2)
{
	Picture tg;
	tg = *pic1;
	*pic1 = *pic2;
	*pic2 = tg;
}

void sapXepTangDanTheoTen(Picture pic[], int soBucTranh)
{
	int i, j;
	for (i = 0; i < soBucTranh - 1; i++)
	{
		for (j = i + 1; j < soBucTranh; j++)
		{
			if (strcmp(pic[i].ten, pic[j].ten) > 0)
			{
				hoanViTranh(&pic[i], &pic[j]);
			}
		}
	}
	printf("\nSau khi sap xep tang dan theo ten, ta duoc:");
	for (i = 0; i < soBucTranh; i++)
	{
		hienThiTranh(pic[i]);
	}
}

void sapXepTheoDienTichGiamDan(Picture pic[], int soBucTranh)
{
	int i, j;
	for (i = 0; i < soBucTranh - 1; i++)
	{
		for (j = i + 1; j < soBucTranh; j++)
		{
			if (pic[i].dai * pic[i].rong < pic[j].dai * pic[j].rong)
			{
				hoanViTranh(&pic[i], &pic[j]);
			}
		}
	}
	printf("\nSau khi sap xep giam dan theo dien tich, ta duoc:");
	for (i = 0; i < soBucTranh; i++)
	{
		hienThiTranh(pic[i]);
	}
}

void thongKeTranhTheoTenTacGia(Picture pic[], int soBucTranh)
{
	char danhSachTacGia[soBucTranh][30];
	int i, j;
	int soTacGia = 0;
	int timThay;
	for (i = 0; i < soBucTranh; i++)
	{
		timThay = 0;
		for (j = 0; j < soTacGia; j++)
		{
			if (strcmp(danhSachTacGia[j], pic[i].tacGia) == 0)
			{
				timThay = 1;
				break;
			}
		}
		if (timThay == 0)
		{
			strcpy(danhSachTacGia[soTacGia], pic[i].tacGia);
			soTacGia++;
		}
	}
	printf("\nThong ke tranh theo ten tac gia:");
	for (i = 0; i < soTacGia; i++)
	{
		printf("\nTranh cua tac gia %s:", danhSachTacGia[i]);
		for (j = 0; j < soBucTranh; j++)
		{
			if (strcmp(pic[j].tacGia, danhSachTacGia[i]) == 0)
			{
				hienThiTranh(pic[j]);
			}
		}
	}
}

void timTranhTheoTheLoai(Picture pic[], int soBucTranh)
{
	char theLoai[30];
	int timThay = 0;
	int i;
	float giaMin = 1000000;
	fflush(stdin);
	do
	{
		printf("\nMoi nhap the loai muon tim: ");
		gets(theLoai);
	} while (strlen(theLoai) == 0);
	for (i = 0; i < soBucTranh; i++)
	{
		if (strcmp(pic[i].theLoai, theLoai) == 0)
		{
			if (giaMin > pic[i].gia)
			{
				giaMin = pic[i].gia;
				timThay = 1;
			}
		}
	}
	if (!timThay)
	{
		printf("\nKhong co buc tranh nao co the loai: %s", theLoai);
	}
	else
	{
		for (i = 0; i < soBucTranh; i++)
		{
			if (pic[i].gia == giaMin && strcmp(pic[i].theLoai, theLoai) == 0)
			{
				hienThiTranh(pic[i]);
			}
		}
	}
}

void ghiFile(Picture pic[], int soBucTranh)
{
	FILE *fp;
	fp = fopen("tranh.txt", "w");
	if (!fp)
	{
		printf("\nKhong mo duoc file");
		exit(1);
	}
	int i;
	fputs("Thong tin cac buc tranh:", fp);
	for (i = 0; i < soBucTranh; i++)
	{
		fprintf(fp, "\nBuc tranh thu %d:", i + 1);
		fprintf(fp, "\nTen tranh: %s", pic[i].ten);
		fprintf(fp, "\nTac gia: %s", pic[i].tacGia);
		fprintf(fp, "\nThe loai: %s", pic[i].theLoai);
		fprintf(fp, "\nDai: %g", pic[i].dai);
		fprintf(fp, "\nRong: %g", pic[i].rong);
		fprintf(fp, "\nGia ban: %g", pic[i].gia);
	}
	fflush(stdin);
	fclose(fp);
}

void docFile()
{
	FILE *fp;
	fp = fopen("tranh.txt", "r");
	if (!fp)
	{
		puts("\nKhong mo duoc file");
		exit(1);
	}
	char data[1000];
	fgets(data, 500, fp);
	puts(data);
	fflush(stdin);
	fclose(fp);
}

int main()
{
	int soBucTranh;
	menu();
	int option;
	Picture pic[10];
	while (1)
	{
		printf("\nMoi chon 1 muc: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			soBucTranh = nhapSoLuongTranh();
			nhapThongTinTranh(pic, soBucTranh);
			hienThiThongTinCacTranh(pic, soBucTranh);
			break;
		case 2:
			sapXepTangDanTheoTen(pic, soBucTranh);
			break;
		case 3:
			sapXepTheoDienTichGiamDan(pic, soBucTranh);
			break;
		case 4:
			thongKeTranhTheoTenTacGia(pic, soBucTranh);
			break;
		case 5:
			timTranhTheoTheLoai(pic, soBucTranh);
			break;
		case 6:
			ghiFile(pic, soBucTranh);
			break;
		case 7:
			docFile();
			break;
		case 8:
			return 0;
		}
	}

	return 0;
}