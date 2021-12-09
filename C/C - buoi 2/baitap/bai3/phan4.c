#include <stdio.h>

int main() {
    int i;
    int tong = 0;
    for (i = 2; i <= 100; i= i + 2)
    {
        tong = tong + i;
    }
    printf("\nTong cua 50 so chan la: %d",tong);
    return 0;
}