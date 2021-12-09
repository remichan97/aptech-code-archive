#include <stdio.h>

int main() {
    int i;
    int tong = 0;
    for (i = 1; i <= 50; i++)
    {
        tong = tong + i;
    }
    printf("\nTong day so tu 1 den 50 la: %d",tong);
    return 0;
}