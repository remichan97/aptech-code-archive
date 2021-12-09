#include <stdio.h>

int main()
{
    float S = 0;
    int i;
    int n;
    do
    {
        printf("\nNhap mot so bat ky (>=1): ");
        scanf("%d", &n);
    } while (n < 1);
    for (i = 1; i <= n; i++)
    {
        S += 1.0 / i; //or S += 1/(float)i;
    }
    printf("\nTong nghich dao tu 1 den %d la: %g", n, S);
    return 0;
}