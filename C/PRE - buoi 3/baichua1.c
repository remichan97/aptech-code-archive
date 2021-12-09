#include <stdio.h>

int main() {
    int number;
    printf("\nMoi nhap mot so: ");
    scanf("%d",&number);
    printf("\nSau khi nhap, so la: %d",number);
    number=100;
    printf("\nSau khi luu 100, so moi la: %d",number);
    number=number+200;/*or number+=200
    tương tự vậy:
    number-=200
    number*=200
    number/=200
    number%=200*/
    printf("\nSo moi sau khi cong them 200 la: %d",number);
    return 0;
}