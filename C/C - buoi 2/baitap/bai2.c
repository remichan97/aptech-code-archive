#include <stdio.h>

int main() {
    int i, n = 50;
    for  (i = 1; i <= 2018; i++)
    {
        n = n + i;
    }
    printf("\nSo thu 2019 cua day so vo han 50, 51, 53, 56, 60,... la: %d",n);
    return 0;
}