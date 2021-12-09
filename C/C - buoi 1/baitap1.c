#include <stdio.h>
#include <math.h>

int main()
{
    float N;
    printf("\nNhap mot so bat ky: ");
    scanf("%f", &N);
    if (N - (int)N != 0)
    {
        printf("\nSo vua nhap la so thuc.");
    }
    else
    {
        printf("\nSo vua nhap la so nguyen.");
    }
    if ((int)N % 2 != 0)
    {
        printf("\nSo vua nhap la so le.");
    }
    else
    {
        printf("\nSo vua nhap la so chan.");
    }
    if ((int)N % 2 == 0 && N > 0)
    {
        printf("\nSo vua nhap la so chan duong.");
    }
    else
    {
        printf("\nSo vua nhap khong phai la so chan duong.");
    }
    if ((int)N % 2 != 0 && N < 0)
    {
        printf("\nSo vua nhap la so le am.");
    }
    else
    {
        printf("\nSo vua nhap khong phai la so le am.");
    }

    if ((int)N > 0 && (sqrt(N) == (int)sqrt(N)))
    {
        printf("\nSo vua nhap la so chinh phuong.");
    }
    else
    {
        printf("\nSo vua nhap khong phai la so chinh phuong.");
    }
    if (N > 0 && N < 1000)
    {
        int Donvi;
        Donvi = (int)N % 10;
        int Chuc;
        Chuc = (int)N / 10 % 10;
        int Tram;
        Tram = (int)N / 100 % 10;
        if (N == pow(Donvi, 3) + pow(Chuc, 3) + pow(Tram, 3))
        {
            printf("\nSo vua nhap la so dac biet.");
        }
        else
        {
            printf("\nSo vua nhap khong phai la so dac biet.");
        }
    }
}