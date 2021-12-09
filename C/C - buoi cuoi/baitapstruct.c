#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sv
{
	char hoTen[50];
	char gioiTinh[20];
	float diemPython;
	float diemC;
} hocvien;

void menu()
{
	printf("\n===CHUONG TRINH QUAN LY DIEM HOC VIEN===");
	printf("\n1. Nhap thong tin hoc vien.");
	printf("\n2. Xet ket qua.");
	printf("\n3. In danh sach da nhap.");
	printf("\n4. Sap xep theo thu tu giam dan theo diem trung binh.");
	printf("\n5. Tim kiem hoc vien.");
	printf("\n6. Danh sach sinh vien da dau.");
	printf("\n7. Danh sach sinh vien da truot.");
	printf("\n8. Ghi file.");
	printf("\n9. Doc file.");
	printf("\n10. Ket thuc chuong trinh.");
}

int nhapSoLuong()
{
	int qty;
	printf("\nNhap so luong hoc vien: ");
	scanf("%d", &qty);
	return qty;
}

void nhapThongTin(int qty, hocvien sinhVien[])
{
	int i;
	printf("\nNhap thong tin cho tung hoc vien:");
	for (i = 0; i < qty; i++)
	{
		fflush(stdin);
		printf("\nHoc vien thu %d:", i + 1);
		do
		{
			printf("\nNhap ten hoc vien: ");
			gets(sinhVien[i].hoTen);
		} while (strlen(sinhVien[i].hoTen) == 0);
		do
		{
			printf("\nNhap gioi tinh hoc vien: ");
			gets(sinhVien[i].gioiTinh);
		} while (strlen(sinhVien[i].gioiTinh) == 0);
		printf("\nNhap dien C: ");
		scanf("%f", &sinhVien[i].diemC);
		printf("\nNhap diem Python: ");
		scanf("%f", &sinhVien[i].diemPython);
	}
}

void hienThiThongTin(hocvien sinhVien)
{
	printf("\nTen hoc vien: %s \n", sinhVien.hoTen);
	printf("\nGioi tinh: %s \n", sinhVien.gioiTinh);
	printf("\nDien C cua hoc vien: %g \n", sinhVien.diemC);
	printf("\nDiem Python cua hoc vien: %g \n", sinhVien.diemPython);
}

void hienThiNhieuThongTin(int qty, hocvien sinhVien[])
{
	int i;
	printf("\nDuoi day la thong tin ban da nhap:");
	for (i = 0; i < qty; i++)
	{
		hienThiThongTin(sinhVien[i]);
	}
}

float diemTb(hocvien sinhVien)
{
	float tb;
	tb = ((sinhVien.diemC * 2) + sinhVien.diemPython) / 3;
	return tb;
}

void xepLoai(int qty, hocvien sinhVien[])
{
	int i;
	for (i = 0; i < qty; i++)
	{
		if (diemTb(sinhVien[i]) >= 5 && (diemTb(sinhVien[i]) < 5 && (strcmp("Nu", sinhVien[i].gioiTinh) == 0 || (strcmp("nu", sinhVien[i].gioiTinh)))))
		{
			printf("\nHoc vien %s da dau.\n", sinhVien[i].hoTen);
		}
		else if (diemTb(sinhVien[i]) < 5 && (strcmp("Nam", sinhVien[i].gioiTinh) == 0 || (strcmp("nam", sinhVien[i].gioiTinh) == 0)))
		{
			printf("\nHoc vien %s da truot.\n", sinhVien[i].hoTen);
		}
		else
		{
			printf("\nHoc vien %s da dau.\n", sinhVien[i].hoTen);
		}
	}
}

void danhSachKetQua(int qty, hocvien sinhVien[])
{
	int i;
	printf("\nDuoi day la thong tin cua tung hoc vien:");
	for (i = 0; i < qty; i++)
	{
		printf("\nHoc vien thu %d", i + 1);
		hienThiThongTin(sinhVien[i]);
		printf("\nDiem trung binh cua hoc vien la: %.2f\n", diemTb(sinhVien[i]));
		if (diemTb(sinhVien[i]) >= 5 && (diemTb(sinhVien[i]) < 5 && (strcmp("Nu", sinhVien[i].gioiTinh) == 0 || (strcmp("nu", sinhVien[i].gioiTinh)))))
		{
			printf("\nHoc vien %s da dau.\n", sinhVien[i].hoTen);
		}
		else if (diemTb(sinhVien[i]) < 5 && (strcmp("Nam", sinhVien[i].gioiTinh) == 0 || (strcmp("nam", sinhVien[i].gioiTinh) == 0)))
		{
			printf("\nHoc vien %s da truot.\n", sinhVien[i].hoTen);
		}
		else
		{
			printf("\nHoc vien %s da dau.\n", sinhVien[i].hoTen);
		}
	}
	printf("\nViec hien thi ket qua da hoan tat.");
}

void sapXepGiamDan(int qty, hocvien sinhVien[])
{
	int i, j;
	hocvien tg;
	for (i = 0; i < qty - 1; i++)
	{
		for (j = i + 1; j < qty; j++)
		{
			if (diemTb(sinhVien[i]) > diemTb(sinhVien[j]))
			{
				tg = sinhVien[i];
				sinhVien[i] = sinhVien[j];
				sinhVien[j] = tg;
			}
		}
	}
	printf("\nSau khi sap xep, ta co:");
	for (i = 0; i < qty; i++)
	{
		hienThiThongTin(sinhVien[i]);
	}
}

void timKiem(int qty, hocvien sinhVien[])
{
	int i;
	char tuKhoa[50];
	printf("\nNhap ten hoc vien ban muon tim: ");
	gets(tuKhoa);
	for (i = 0; i < qty; i++)
	{
		printf("\nKet qua tim kiem hoc vien %s:", tuKhoa);
		if (strcmp(tuKhoa, sinhVien[i].hoTen) == 0)
		{
			hienThiThongTin(sinhVien[i]);
		}
	}
	printf("\nKet thuc viec tim kiem.");
}

void danhSachDau(int qty, hocvien sinhVien[])
{
	int i;
	printf("\nDanh sach hoc vien da dau:");
	for (i = 0; i < qty; i++)
	{
		if (diemTb(sinhVien[i]) < 5 && (strcmp("Nam", sinhVien[i].gioiTinh) == 0 || (strcmp("nam", sinhVien[i].gioiTinh) == 0)))
		{
			hienThiThongTin(sinhVien[i]);
		}
		else
		{
			printf("\nViec hien thi da hoan tat.");
		}
	}
}
void danhSachTruot(int qty, hocvien sinhVien[])
{
	int i;
	printf("\nDanh sach hoc vien da truot:");
	for (i = 0; i < qty; i++)
	{
		if (diemTb(sinhVien[i]) >= 5 && (diemTb(sinhVien[i]) < 5 && (strcmp("Nu", sinhVien[i].gioiTinh) == 0 || (strcmp("nu", sinhVien[i].gioiTinh)))))
		{
			hienThiThongTin(sinhVien[i]);
		}
		else
		{
			printf("\nViec hien thi da hoan tat.");
		}
	}
}

void ghiFile(int qty, hocvien sinhVien[])
{
	int i;
	FILE *sv;
	sv = fopen("sinhvien.txt", "w");
	if (sv == NULL)
	{
		printf("\nViec tao tap tin that bai.");
		exit(1);
	}
	for (i = 0; i < qty; i++)
	{
		fprintf(sv, "\nHoc vien thu %d:", i + 1);
		fprintf(sv, "\nHo ten hoc vien: %s\n", sinhVien[i].hoTen);
		fprintf(sv, "\nGioi tinh hoc vien: %s\n", sinhVien[i].gioiTinh);
		fprintf(sv, "\nDiem C: %g\n", sinhVien[i].diemC);
		fprintf(sv, "\nDiem Python: %g\n", sinhVien[i].diemPython);
		fprintf(sv, "\nDiem TB: %.2f\n", diemTb(sinhVien[i]));
		fprintf(sv, "\n**************************");
	}
	fclose(sv);
	printf("\nKet xuat file thanh cong, vui long tim den tap tin 'sinhvien.txt' nam o thu muc chua chuong trinh");
}

void docFile()
{
	FILE *sv;
	sv = fopen("sinhvien.txt", "r");
	char c;
	printf("\nDuoi day la noi dung tap tin:\n");
	if (sv == NULL)
	{
		printf("\nKhong the mo tap tin. Co the do ban chua ket xuat tap tin nao.");
		exit(1);
	}
	else
	{
		while ((c = getc(sv)) != EOF)
		{
			printf("%c", c);
		}
	}
	fclose(sv);
	printf("\nViec doc tap tin da ket thuc.");
}

int main()
{
	hocvien sinhVien[10];
	int option, qty;
	while (1)
	{
		menu();
		do
		{
			printf("\nMoi ban chon chuc nang: ");
			scanf("%d", &option);
		} while (!(1 <= option && option <= 10));
		switch (option)
		{
		case 1:
			printf("\n===Nhap thong tin hoc vien===");
			qty = nhapSoLuong();
			nhapThongTin(qty, sinhVien);
			hienThiNhieuThongTin(qty, sinhVien);
			fflush(stdin);
			printf("\nViec nhap lieu da hoan tat.");
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 2:
			fflush(stdin);
			printf("\n===Xet loai hoc vien===");
			xepLoai(qty, sinhVien);
			printf("\nKet thuc viec xet hoc vien.");
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 3:
			fflush(stdin);
			printf("\n===In danh sach hoc vien, bao gom diem tb, ket qua===");
			danhSachKetQua(qty, sinhVien);
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 4:
			printf("\n===Sap xep giam dan theo diem trung binh===");
			sapXepGiamDan(qty, sinhVien);
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 5:
			fflush(stdin);
			printf("\n===Tim kiem hoc vien===");
			timKiem(qty, sinhVien);
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 6:
			fflush(stdin);
			printf("\n===Danh sach dau===");
			danhSachDau(qty, sinhVien);
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 7:
			fflush(stdin);
			printf("\n===Danh sach truot===");
			danhSachTruot(qty, sinhVien);
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 8:
			fflush(stdin);
			printf("\n===Ghi ra file===");
			ghiFile(qty, sinhVien);
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		case 9:
			fflush(stdin);
			printf("\n===Doc tap tin===");
			docFile();
			printf("\nNhan phim Enter de tro ve man hinh chinh...");
			getchar();
			break;
		default:
			printf("\nKet thuc chuong trinh, chuyen ve dau nhac lenh...");
			return 0;
			break;
		}
	}
	return 0;
}