#include <stdio.h>

int main()
{
    /*Vòng lặp for: Được coi là một vòng lặp xác định.
    Cú pháp:
    for (khởi_tạo_biến_đếm; điều_kiện; thay_đổi_biến_đếm)
    {
        code ở đây
    } (khởi tạo giá trị cho biến đếm, kiểm tra điều kiện, xong chạy lệnh, rồi thay đổi biến đếm, lặp đến khi sai điều kiên thì thoát vòng lặp)
    Ví dụ: In ra các số từ 1 đến 100*/
    int i;
    for (i = 1; i <= 100; i++) //(i+=1 tương đương với i++)
    {
        printf("%d ", i);
    }
    return 0;
}