#include <stdio.h>

int main()
{
    int i, a, b, flag;
    printf("\nNhap so thu nhat: ");
    scanf("%d", &a);
    printf("\nNhap so thu hai: ");
    scanf("%d", &b);
    for (i = 1; i <= a || i <= b; i++)
    {
        if (a % i == 0 && b % i == 0) {
            flag = i;
        }
    }
    printf("\nUCLN cua a va b la: %d",flag);
    printf("\nBCNN cua a va b la: %d", (a*b)/flag);
    return 0;
}