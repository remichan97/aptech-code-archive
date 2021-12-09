#include <stdio.h>
#include <math.h>

int main() {
    int i, n, a, b = 0;
    printf("\nNhap mot so n bat ky: ");
    scanf("%d",&n);
    for (i = 0; i <= n; i++)
    {
        a = pow(i,3);
        b = b + a;
    }
    printf("\nTong bac 3 cua %d la: %d",n, b);
    return 0;
}