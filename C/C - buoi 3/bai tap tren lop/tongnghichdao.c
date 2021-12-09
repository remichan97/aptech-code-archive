#include <stdio.h>

int main() {
    float s = 0;
    float i, n;
    printf("\nNhap mot so bat ky: ");
    scanf("%f",&n);
    for (i = 1; i <= n; i++)
    {
        s = s + 1/i;
    }
    printf("\nTong nghich dao cua so do la: %f",s);
    return 0;
}