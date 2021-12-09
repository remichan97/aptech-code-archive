#include <stdio.h>
#include <stdlib.h>

void menu()
{
	printf("\n1. ");
	printf("\n2. ");
	printf("\n3. ");
	printf("\n4. ");
	printf("\n5. ");
	printf("\n6. ");
	printf("\n7. ");
	printf("\n8. ");
	printf("\n9. ");
	printf("\n10. ");
	printf("\n11. ");
	printf("\n12. ");
	printf("\n13. Thoat");
}

void nhapN(int *p)
{
	do
	{
		printf("\nNhap N: ");
		scanf("%d", &*p);
	} while (!(0 < *p && *p < 50));
}

void nhapMang(float *p, int N)
{
	int i;
	printf("\nNhap lieu cho mang:");
	for (i = 0; i < N; i++)
	{
		printf("\nPhan tu thu %d: ", i + 1);
		scanf("%f", &p[i]); //or p + i
	}
}

int main()
{
	menu();
	int option, N;
	float *arr;
	while (1)
	{
		printf("\nMoi chon 1 muc: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			nhapN(&N);
			break;
		case 2:
			arr = (float *)malloc(N * sizeof(float));
			nhapMang(arr, N);
			break;
		case 13:
			return 0;
			break;
		}
	}

	return 0;
}