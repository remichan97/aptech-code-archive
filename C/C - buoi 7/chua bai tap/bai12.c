#include <stdio.h>
#include <string.h>

int main()
{
	char b[49] = "ABCDBa123bxyzatbuvAKBYTAPO";
	int i;
	int dem;
	int j;
	int daDem;
	for (i = 0; i < strlen(b); i++)
	{
		dem = 0;
		daDem = 0;
		if (i == 0)
		{
			for (j = 0; j < strlen(b); j++)
			{
				if (b[i] == b[j])
				{
					dem++;
				}
			}
			printf("\nKy tu '%c' xuat hien %d lan.", b[i], dem);
		}
		else
		{
			for (j = 0; j < i; j++)
			{
				if (b[j] == b[i])
				{
					daDem = 1;
				}
			}
			if (daDem == 1)
			{
				continue; //bỏ qua trùng lặp, tiếp tục vòng lặp
			}
			else
			{
				for (j = i; j < strlen(b); j++)
				{
					if (b[i] == b[j])
					{
						dem++;
					}
				}
				printf("\nKy tu '%c' xuat hien %d lan.", b[i], dem);
			}
		}
	}

	return 0;
}