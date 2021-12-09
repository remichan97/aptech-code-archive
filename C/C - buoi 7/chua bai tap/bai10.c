#include <stdio.h>
#include <string.h>

int main()
{
	char a[49] = "ab     cd          EF";
	int i;
	int j;
	int count = 0;
	for (i = 0; i < strlen(a); i++)
	{
		while (a[i] == ' ' && a[i + 1] == ' ')
		{
			count++;
			for (j = i + 1; j < strlen(a); j++)
			{
				a[j - 1] = a[j];
			}
		}
	}
	a[strlen(a) - count] = '\0';
	puts(a);
	return 0;
}