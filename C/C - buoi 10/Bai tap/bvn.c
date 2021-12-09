#include <stdio.h>
#include <string.h>

int main()
{
	int i, count = 0, j;
	char chuoi[30];
	printf("\nNhap vao mot chuoi bat ky: ");
	gets(chuoi);
	int banDau = strlen(chuoi);
	for (i = 0; i < strlen(chuoi); i++)
	{
		if (('A' <= chuoi[i] && chuoi[i] <= 'Z') && ('A' <= chuoi[i + 1] && chuoi[i + 1] <= 'Z'))
		{
			for (j = strlen(chuoi); j > i; j--)
			{
				chuoi[j] = chuoi[j - 1];
			}
			chuoi[i + 1] = ' ';
			count++;
		}
	}
	chuoi[banDau + count] = '\0';
	printf("\nChuoi sau khi chen space la: %s", chuoi);
	return 0;
}