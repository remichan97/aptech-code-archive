#include <stdio.h>

int main()
{
    int soDoan, soNgaunhien, soLandoan;
    soNgaunhien = srand() % 1000;
    printf("\nMoi ban doan mot so: ");
    scanf("%d", &soDoan);
    soLandoan = 0;
    while (soDoan != soNgaunhien)
    {
        soLandoan++;
        if (soDoan > soNgaunhien)
        {
            printf("\nSo ban doan lon hon so can doan, moi ban doan lai: ");
        }
        else
        {
            printf("\nSo ban doan nho hon so can doan, moi ban doan lai: ");
        }
        scanf("%d", &soDoan);
    }
    printf("\nBan da doan dung, xin chuc mung!");
    printf("\nSo lan doan cua ban la %d", soLandoan);
    return 0;
}