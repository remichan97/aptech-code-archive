#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    printf("\nNhap vao mot so bat ky: ");
    scanf("%d",&n);
    if (n < 2)
    {
        printf("\nSo vua nhap khong phai la so nguyen to.");
    }
    int count = 0;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            count++; //đếm xem có bao nhiêu số chia hết cho số vừa nhập
        }
    }
    if (count == 0)
    {
        printf("\nSo vua nhap la so nguyen to.");
    }
    else
    {
        printf("\nSo vua nhap khong phai la so nguyen to.");
    }
    
        
    return 0;
}