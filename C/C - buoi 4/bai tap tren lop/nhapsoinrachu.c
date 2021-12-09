#include <stdio.h>

int main() {
    int n;
    do
    {
        printf("\nNhap mot so tu 0 den 9: ");
        scanf("%d",&n);
    } while (!(n >= 0 && n <= 9));
    switch (n)
    {
    case 0:
        printf("\nKhong");
        break;
    case 1:
        printf("\nMot");
        break;
    case 2:
        printf("\nHai");
        break;
    case 3:
        printf("\nBa");
        break;
    case 4:
        printf("\nBon");
        break;
    case 5:
        printf("\nNam");
        break;
    case 6:
        printf("\nSau");
        break;
    case 7:
        printf("\nBay");
        break;
    case 8:
        printf("\nTam");
        break;
    default:
    printf("\nChin");
        break;
    }
    return 0;
}