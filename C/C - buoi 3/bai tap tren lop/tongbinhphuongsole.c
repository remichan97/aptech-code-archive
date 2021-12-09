#include <stdio.h>
#include <math.h>

int main() {
    int i, n, tong = 0;
    printf("\nNhap mot so bat ky de tinh tong binh phuong so le: ");
    scanf("%d",&n);
    for (i = 1; i <= n; i+=2)
    {
        tong = tong + pow(i,2);
    }
    printf("\nTong binh phuong so le tu 1 den so da nhap la: %d",tong);
    return 0;
}