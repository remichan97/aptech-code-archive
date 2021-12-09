#include <stdio.h>

int main() {
    /*do-while: vòng lặp không xác định
    cú pháp:
    do
    {
        code ở đây
    } while (điều_kiện); (thực hiện code trong đây xong mới kiểm tra điều kiện, sai điều kiện thì thoát vòng lặp)
    ví dụ: nhập một số nguyên trong khoảng từ 0 đến 100*/
    int number;
    do
    {
        printf("\nNhap mot so nguyen trong khoang tu 0 den 100: ");
        scanf("%d",&number);
    } while (!(0 <= number && number <=100));
    printf("\nSau khi nhap, number= %d",number);
    return 0;
}