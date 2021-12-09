#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, i;
    printf("\n nhap so a = ");
    scanf("%d", &a);
    printf("\n nhap so b= ");
    scanf("%d", &b);
    //giai thuat tim ucln và bcnn
    for (i = a; i <= a || i <= b; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            printf("\n %d", i);
            break;
        }
    }
    printf("\n %d", (a * b) / i);
}