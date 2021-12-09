#include <stdio.h>

int main() {
    int i, danSo = 6000000;
    for (i = 1; i <= 10; i++)
    {
        danSo = (danSo + (danSo * 0.018));
    }
    printf("\nDan so sau 10 nam cua thanh pho la: %d", danSo);
    return 0;
}