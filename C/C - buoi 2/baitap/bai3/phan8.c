#include <stdio.h>

void muoiba()
{
    int i, t1 = 0, t2 = 1, trungGian;
    for (i = 1; i <= 13; ++i)
    {
        trungGian = t1 + t2;
        t1 = t2;
        t2 = trungGian;
    }
    printf("\nSo thu 13 trong day Fibonacci la: %d", trungGian);
}
int main()
{
    int i, t1 = 0, t2 = 1, trungGian;
    printf("\nMuoi so dau cua day Fibonacci la: ");
    for (i = 1; i <= 10; ++i)
    {
        printf("%d ", t1);
        trungGian = t1 + t2;
        t1 = t2;
        t2 = trungGian;
    }
    muoiba();
    return 0;
}
