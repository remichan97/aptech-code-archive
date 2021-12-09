#include <stdio.h>

int main() {
    int i;
    int tong = 0;
    for (i = 5; i <= 100; i = i + 5)
    {
        tong = tong + i;
    }
    printf("\nTong cua 20 so bat dau tu 5 den 100 la: %d",tong);
    return 0;
}