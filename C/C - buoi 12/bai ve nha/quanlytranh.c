#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tranh
{
	char ten[50];
	char tacGia[50];
	char theLoai[30];
	float dai;
	float rong;
	float giaBan;
} tranh;

void menu()
{
	printf("\n===CHUONG TRINH QUAN LY TRANH===");
	printf("\nMoi ban chon mot trong cac chuc nang sau:");
	printf("\n1. Nhap thong tin tranh va hien thi ra man hinh.");
	printf("\n2. Sap xep tang dan theo bang chu cai.");
	printf("\n3. Sap xep cac tranh theo dien tich gian dan.");
	printf("\n4. Thong ke tranh theo ten tac gia.");
	printf("\n5. Tim va hien thi theo the loai, gia ban thap nhat va nho nhat.");
	printf("\n6. Ghi ra file.");
	printf("\n7. Doc mot file.");
	printf("\n8. Ket thuc chuong trinh.");
}

tranh nhapDuLieu()
{
	tranh tacPham;
	printf("\nNhap ten tac pham: ");
	gets(tacPham.ten);
	printf("\nNhap ten tac gia: ");
	gets(tacPham.tacGia);
	printf("\nNhap the loai tac pham: ");
	gets(tacPham.theLoai);
	printf("\nNhap chieu dai tac pham theo don vi (cm): ");
	scanf("%f", &tacPham.dai);
	printf("\nNhap chieu rong tac pham theo don vi (cm): ");
	scanf("%f", &tacPham.rong);
	printf("\nNhap gia ban tac pham theo don vi $: ");
	scanf("%f", &tacPham.giaBan);
	fflush(stdin);
	return tacPham;
}

void nhapNhieuDuLieu(tranh nhieuTacPham[], int qty)
{
	int i;
	for (i = 0; i < qty; i++)
	{
		printf("\nBuc tranh thu %d:", i + 1);
		nhieuTacPham[i] = nhapDuLieu();
	}
}

void inThongTin(tranh tacPham)
{
	printf("\nTen tac pham: %s", tacPham.ten);
	printf("\nTen tac gia: %s", tacPham.tacGia);
	printf("\nThe loai: %s", tacPham.theLoai);
	printf("\nChieu dai (cm): %g", tacPham.dai);
	printf("\nChieu rong (cm): %g", tacPham.rong);
	printf("\nGia ban ($): %g", tacPham.giaBan);
}

void inNhieuThongTin(tranh nhieuTacPham[], int qty)
{
	int i;
	for (i = 0; i < qty; i++)
	{
		printf("\nBuc tranh thu %d", i + 1);
		inThongTin(nhieuTacPham[i]);
	}
}

void sapXepTheoTen(tranh nhieuTacPham[], int qty)
{
	int i, j;
	tranh tg;
	for (i = 0; i < qty - 1; i++)
	{
		for (j = i + 1; j < qty; j++)
		{
			if (strcmp(nhieuTacPham[i].ten, nhieuTacPham[j].ten) > 0)
			{
				tg = nhieuTacPham[i];
				nhieuTacPham[i] = nhieuTacPham[j];
				nhieuTacPham[j] = tg;
			}
		}
	}
	printf("\nKet thuc viec sap xep, ta duoc:");
	inNhieuThongTin(nhieuTacPham, qty);
}

void sapXepTheoDienTich(tranh nhieuTacPham[], int qty)
{
	int i, j;
	tranh dt;
	for (i = 0; i < qty - 1; i++)
	{
		for (j = i + 1; j < qty; j++)
		{
			if ((nhieuTacPham[i].dai * nhieuTacPham[i].rong) < (nhieuTacPham[j].dai * nhieuTacPham[j].rong))
			{
				dt = nhieuTacPham[i];
				nhieuTacPham[i] = nhieuTacPham[j];
				nhieuTacPham[j] = dt;
			}
		}
	}
	printf("\nKet thuc viec sap xep, ta duoc:");
	inNhieuThongTin(nhieuTacPham, qty);
}

void thongKeTheoTacGia(tranh nhieuTacPham[], int qty)
{
	int i, j;
	tranh tg;
	for (i = 0; i < qty - 1; i++)
	{
		for (j = i + 1; j < qty; j++)
		{
			if (strcmp(nhieuTacPham[i].tacGia, nhieuTacPham[j].tacGia) == 0)
			{
				tg = nhieuTacPham[i];
				nhieuTacPham[i] = nhieuTacPham[j];
				nhieuTacPham[j] = tg;
			}
		}
	}
	inNhieuThongTin(nhieuTacPham, qty);
}

void hienThiTheoTheLoai(tranh nhieuTacPham[], int qty)
{
	int i, j;
	tranh tl;
	for (i = 0; i < qty - 1; i++)
	{
		for (j = i + 1; j < qty; j++)
		{
			if (strcmp(nhieuTacPham[i].theLoai, nhieuTacPham[j].theLoai) == 0)
			{
				tl = nhieuTacPham[i];
				nhieuTacPham[i] = nhieuTacPham[j];
				nhieuTacPham[j] = tl;
			}
		}
	}
	inNhieuThongTin(nhieuTacPham, qty);
}

void hienThiTheoGiaThapNhat(tranh nhieuTacPham[], int qty)
{
	int i, j;
	tranh giaThapNhat;
	for (i = 0; i < qty - 1; i++)
	{
		for (j = i + 1; j < qty; j++)
		{
			if (nhieuTacPham[i].giaBan < nhieuTacPham[j].giaBan)
			{
				giaThapNhat = nhieuTacPham[i];
				nhieuTacPham[i] = nhieuTacPham[j];
				nhieuTacPham[j] = giaThapNhat;
			}
		}
	}
	inNhieuThongTin(nhieuTacPham, qty);
}

void ghiFile(tranh nhieuTacPham[], int qty)
{
	int i;
	FILE *fp;
	fp = fopen("tranh.txt", "w");
	if (fp == NULL)
	{
		printf("\nKhong the mo tap tin!");
		exit(1);
	}
	for (i = 0; i < qty; i++)
	{
		fprintf(fp, "\nBuc tranh thu %d\n", i + 1);
		fprintf(fp, "\nTen tac pham: %s\n", nhieuTacPham[i].ten);
		fprintf(fp, "\nTen tac gia: %s\n", nhieuTacPham[i].tacGia);
		fprintf(fp, "\nThe loai tac pham: %s\n", nhieuTacPham[i].theLoai);
		fprintf(fp, "\nChieu dai (cm): %g\n", nhieuTacPham[i].dai);
		fprintf(fp, "\nChieu rong (cm): %g\n", nhieuTacPham[i].rong);
		fprintf(fp, "\nGia ban ($): %g\n", nhieuTacPham[i].giaBan);
		fprintf(fp, "**********************");
	}
	fclose(fp);
	printf("\nKet xuat tap tin thanh cong. Vui long tim den tap tin ten 'tranh.txt' nam o thu muc chinh cua chuong trinh.");
}

void docFile()
{
	char c;
	FILE *fp;
	fp = fopen("tranh.txt", "r");
	printf("\nDuoi day la noi dung tap tin:");
	if (fp == NULL)
	{
		printf("\nKhong the mo tap tin, co the do ban chua ket xuat tap tin nao hoac ban khong co quyen doc/ghi o thu muc nay.");
	}
	else
	{
		while ((c = getc(fp)) != EOF)
		{
			printf("%c", c);
		}
	}
	fclose(fp);
	printf("\nViec doc tap tin da ket thuc.");
}

int main()
{
	int option, qty = 5, xacNhan;
	tranh tacPham[qty];
	while (1)
	{
		menu();
		do
		{
			printf("\nMoi nhap lua chon cua ban: ");
			scanf("%d", &option);
		} while (!(1 <= option && option <= 8));
		fflush(stdin);
		switch (option)
		{
		case 1:
			printf("\n===Nhap va in thong tin===");
			xacNhan = 1;
			nhapNhieuDuLieu(tacPham, qty);
			printf("\nDuoi day la thong tin ban da nhap:");
			inNhieuThongTin(tacPham, qty);
			printf("\nViec nhap lieu da hoan tat.");
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 2:
			printf("\n===Sap xep tang dan theo bang chu cai===");
			if (xacNhan != 1)
			{
				printf("\nChua nhap du lieu, vui long nhap du lieu truoc khi thuc hien chuc nang.");
				continue;
			}
			else
			{
				sapXepTheoTen(tacPham, qty);
			}
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 3:
			printf("\n===Sap xep giam dan theo dien tich===");
			if (xacNhan != 1)
			{
				printf("\nChua nhap du lieu, vui long nhap du lieu truoc khi thuc hien chuc nang.");
				continue;
			}
			else
			{
				sapXepTheoDienTich(tacPham, qty);
			}
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 4:
			printf("\n===Thong ke theo ten tac gia===");
			if (xacNhan != 1)
			{
				printf("\nChua nhap du lieu, vui long nhap du lieu truoc khi thuc hien chuc nang.");
				continue;
			}
			else
			{
				thongKeTheoTacGia(tacPham, qty);
			}
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 5:
			if (xacNhan != 1)
			{
				printf("\nChua nhap du lieu, vui long nhap du lieu truoc khi thuc hien chuc nang.");
				continue;
			}
			else
			{
				printf("\n===Hien thi theo the loai===");
				hienThiTheoTheLoai(tacPham, qty);
				printf("\n===Hien thi theo gia thap nhat");
				hienThiTheoGiaThapNhat(tacPham, qty);
				printf("\n===San phaam co nho nhat===");
				sapXepTheoDienTich(tacPham, qty);
			}
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 6:
			printf("\n===Ket xuat tap tin===");
			if (xacNhan != 1)
			{
				printf("\nChua nhap du lieu, vui long nhap du lieu truoc khi thuc hien chuc nang.");
				continue;
			}
			else
			{
				ghiFile(tacPham, qty);
			}
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 7:
			printf("\n===Doc tap tin===");
			docFile();
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		default:
			printf("\nKet thuc chuong trinh, chuyen ve dau nhac lenh.");
			return 0;
			break;
		}
	}
	return 0;
}