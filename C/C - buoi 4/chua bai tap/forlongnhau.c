#include <stdio.h>

int main() {
    //vòng lặp lồng nhau:
    int j, i, k;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("\nfor1");

        }
        for (k = 0; k < 10; k++)
            {
                printf("\nfor2");
            }
    }
    return 0;
}