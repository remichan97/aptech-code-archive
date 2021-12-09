#include <stdio.h>
#include <math.h>

int main() {
    /*nhập một số bất kỳ, kiểm tra xem số đó có phải là số nguyên tố hay không?*/
    float N;
    int flag = 0;
    int i;
    printf("\nNhap mot so bat ky: ");
    scanf("%f",&N);
    if (N < 2)
    {
        printf("\n%g khong phai la so nguyen to.", N);
    } else
    {
        if (N == (int)N)
        {
            for (i = 2; i <= sqrt(N); i++)
            {
                if ((int)N % i == 0)
                {
                    flag = 1;
                    break;
                }
            }   
            if (flag == 1)
            {
                printf("\n%g khong phai la so nguyen to.",N);
            } else
            {
                printf("\n%g la so nguyen to.",N);
            }
        } else
        {
            printf("\n%g la so nguyen to.",N);
        }
    }
    return 0;
}