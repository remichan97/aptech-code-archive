#include <stdio.h>

int main() {
    int a, b, c, d;
    for (a = 0; a <= 10; a++)
    {
        for (b = 0; b <= 10; b++)
        {
            for (c = 0; c <= 10; c++)
            {
                for (d = 0; d <= 10; d++)
                {
                    if ((a * d * d == b * c * c * c) && (a != b) && (b != c) && (c != d) && (a != c) && (d != a) && (b != d))
                    {
                        printf("\nCac so a,b,c,d thoa man phep toan a*d*d = b*c*c*c la: %d %d %d %d", a, b, c, d);
                    }
                }
            }
        }
    }
    return 0;
}