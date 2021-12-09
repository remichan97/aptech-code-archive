#include <stdio.h>

int main()
{
    /*Mảng (Array): Là cách thức quản lý thao tác với nhiều dữ liệu một cách thuận tiện, hiệu quả, giúp giảm thời gian và công sức cho lập trình viên.*/
    ///Khai báo mảng:
    ///kiểu_dữ_liệu tên_mảng[size];
    ///kiểu_dữ_liệu: là kiểu mong muốn của lập trình viên, nhưng phải khác void.
    ///tên_mảng: tùy ý lập trình viên, cần tuân theo quy tắc chung (không dấu cách, không phải là phép toán,...).
    ///size: kích thước của mảng, không thể là số < 0.
    ///ví dụ 1:
    int namSinh[5];
    ///namSinh[0] -> Phần tử (biến) đầu tiên.
    ///namSinh[2] -> phần tử thứ 2.
    ///....
    ///namSinh[29] -> phần tử cuối.
    ///Nhập liệu:
    int i;
    printf("\nMoi nhap lieu cho mang: ");
    for (i = 0; i < 5; i++)
    {
        printf("\nPhan tu thu %d: ", i + 1);
        scanf("%d", &namSinh[i]);
    }
    ///Hiển thị dữ liệu mảng:
    printf("\nDu lieu mang: ");
    for (i = 0; i < 5; i++)
    {
        printf("\nnamSinh[%d] = %d", i, namSinh[i]);
    }
    ///Tìm max:
    int max;
    max = namSinh[0];
    for (i = 1; i < 5; i++)
    {
        if (max < namSinh[i])
        {
            max = namSinh[i];
        }
    }
    printf("\nMax = %d", max);
    return 0;
}