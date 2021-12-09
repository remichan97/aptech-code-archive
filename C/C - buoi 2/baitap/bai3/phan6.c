#include <stdio.h>

int main() {
    int i, giaithua = 1, n;
    printf("\nNhap vao mot so de tinh gia thua: ");
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        giaithua = giaithua * i;
    }
    printf("\nGiai thua cua %d la: %d",n,giaithua);
    return 0;
}