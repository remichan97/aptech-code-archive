#include <stdio.h>
int main()
{
    printf("\n1.Nhap vao so nguyen N");
    printf("\n2.Nhap mot mang gom N so thuc");
    printf("\n3.Tim so lon nhat trong mang");
    printf("\n4.");
    printf("\n5.");
    printf("\n6.");
    printf("\n7.");
    printf("\n8.");
    printf("\n9.");
    printf("\n10.");
    printf("\n11.");
    printf("\n12.");
    printf("\n13.Thoat");
    int option;
    while (1)
    {
        printf("\n-------Moi ban chon chuong trinh: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n+++Nhap vao so nguyen N+++\n");
            int N;
            do
            {
                printf("\nMoi ban nhap so nguyen N = ");
                scanf("%d", &N);
            } while (0 >= N || N >= 50);
            break;
        case 2:
            printf("\n+++Nhap mot mang gom N so thuc+++\n");
            int i, mang[49];
            for (i = 0; i < N; i++)
            {
                printf("\nSo phan tu [%d] =", i + 1);
                scanf("%d", &mang[i]);
            }
            break;
        case 3:
            printf("/n+++Tim so lon nhat trong mang+++\n");
            int max;
            max = mang[0];
            for (i = 1; i <= N; i++)
            {
                if (max < mang[i])
                {
                    max = mang[i];
                }
            }
            printf("\nmax=%d", max);
            break;
        case 4:
            printf("/n+++Tim so nho nhat trong mang+++\n");
            int min;
            min = mang[0];
            for (i = 1; i <= N; i++)
            {
                if (min > mang[i])
                {
                    min = mang[i];
                }
            }
            printf("\nmin=%d", min);
            break;
        case 5:
            printf("\n+++Tim so nguyen duong chan lon nhat trong mang+++\n");
            int maxchan;
            maxchan = mang[0];
            for (i = 1; i < N; i++)
            {
                if (mang[i] > 0 && ((int)mang[i] % 2 == 0) && (maxchan < mang[i]))
                {
                    maxchan = mang[i];
                }
            }
            printf("\nmaxchan=%d", maxchan);
            break;
        case 6:
            printf("\n+++Tim so am le nho nhat trong mang +++\n");
            int minle;
            minle = mang[i];
            for (i = 1; i < N; i++)
            {
                if (((int)mang[i] % 2 != 0) && mang[i] < 0 && minle > mang[i])
                {
                    minle = mang[i];
                }
                else
                {
                    printf("\nKhong co so am le nho nhat nao");
                    break;
                }
            }
                    printf("\nminle=%d", minle);
                    break;
        case 13:
            return 0;
        }
    }
}