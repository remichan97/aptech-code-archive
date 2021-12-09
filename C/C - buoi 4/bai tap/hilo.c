#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int i, n, count = 0;
    srand(time(NULL));
    i = rand() % 1000; //sinh số ngẫu nhiên
    while (1)
    {
        printf("\nMoi ban doan mot so bat ky: ");
        scanf("%d", &n);
        count++;
        if (n == i)
        {
            printf("\nChuc mung, ban da doan dung! So can tim la: %d", i);
            printf("\nBan da doan dung so sau %d lan doan.", count);
            break;
        }
        if (n > i)
        {
            printf("\nSo vua nhap lon hon so can tim.");
        }
        if (n < i)
        {
            printf("\nSo vua nhap nho hon so can tim.");
        }
    }
}