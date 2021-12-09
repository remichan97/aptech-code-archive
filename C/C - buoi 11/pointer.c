#include <stdio.h>

void hoanVi(float *p, float *q)
{
	float tg;
	tg = *p;
	*p = *q;
	*q = tg;
}

void nhapLieu(int *p)
{
	printf("\nNhap N: ");
	scanf("%d", &*p);
}

void nhapMang(int *arr, int N)
{
	int i;
	printf("\nMoi nhap lieu cho mang:");
	for (i = 0; i < N; i++)
	{
		printf("\narr[%d]=", i);
		scanf("%d", arr + i);
	}
}

int main()
{

	///Con trỏ (Pointer): Là một loại biến, nó hỗ trợ rất tốt cho lập
	///trình viên trong quá trình thao tác với dữ liệu, cấp phát vùng
	///nhớ,... Trong đó, con trỏ phổ biến được dùng để lưu địa chỉ của
	///biến khác => Giúp lập trình viên làm việc gián tiếp với biến
	///thông qua con trỏ.
	///Khai báo con trỏ:
	///kiểu_dữ_liệu* tên_con_trỏ; hoặc kiểu_dữ_liệu *tên_con_trỏ;
	///Ví dụ:
	int *p; ///Khai báo 1 con trỏ p.
	int N = 10;
	p = &N; ///Cho con trỏ p trỏ tới biến N.
	///Lúc này: *p chứa giá trị của N.
	printf("\n%d", *p);
	///Các thao tác trên *p sẽ là thao tác gián tiếp trên N.
	*p = 50;
	printf("\n%d", N);
	///Ví dụ: Hãy xây dựng hàm dùng để hoán vị giá trị 2 biến a và
	///b cho nhau.
	float a = 5, b = 10;
	hoanVi(&a, &b);
	printf("\nSau khi hoan vi, a=%g, b=%g", a, b);
	///Ví dụ 2: Hãy xây dựng hàm nhập liệu cho N dùng phương pháp con trỏ.
	nhapLieu(&N);
	///Dùng con trỏ để làm việc với mảng:
	///Khai báo 1 con trỏ tương đương với khai báo 1 mảng.
	///Ví dụ:
	int *arr; ///arr là 1 mảng 1 chiều.
	///Cấp phát vùng nhớ cho mảng: https://v1study.com/c-cap-phat-bo-nho-a811.html
	arr = (int *)malloc(N * sizeof(int)); ///stdlib.h
	nhapMang(arr, N);
	printf("\nSau khi nhap lieu, ta duoc:");
	int i;
	for (i = 0; i < N; i++)
	{
		printf("\narr[%d]=%d", i, arr[i]);
	}

	return 0;
}