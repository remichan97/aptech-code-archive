#include <stdio.h>

int main() {
    int i, n;
    printf("\nNhap mot so nguyen: ");
    scanf("%d",&n);
    printf("\nUoc so cua %d la:");
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d ",i);
        }   
    }
    return 0;
}