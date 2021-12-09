#include <stdio.h>

int main() {
    /*Vòng lặp (loop): Dùng để thực hiện lặp đi lặp lại một khối lệnh nào đó nhiều lần. 
    C hỗ trợ 3 loại vòng lặp:
    Vòng lặp while:
    cú pháp:
    while (điều_kiện) {
        khối_lệnh;
    } (lặp đến khi sai điều kiện thì thôi)
    ví dụ: Hãy nhập 1 tháng dương lịch bất kỳ?*/
    int month;
    int count = 0;
    printf("\nNhap mot thang bat ky: ");
    scanf("%d",&month);
    //đi bộ qua chương trình.
    while (!(1 <= month && month <= 12)) //0: sai; 1: đúng
    {
        count++;
        if (count > 3) //kiểm soát số lần nhâp sai
        {
            printf("\nBan da nhap sai qua so lan quy dinh.");
            break;
        }
        printf("\nMoi nhap lai thang: ");
        scanf("%d",&month);
    }
    if (count <= 3)
    {
        printf("\nThang ban vua nhap la: %d",month);
    }
    return 0;
}