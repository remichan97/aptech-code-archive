#include <stdio.h>
int main()
{
    /*if-else: thiết lập điều kiện nhắm kiểm tra dữ liệu xem có hợp lệ theo yêu cầu hay không?
    cú pháp:
    if(đk) {
        code
    }
    else if (đk 2) {
        code
    }
    tương tự với các khối elif khác
    ví dụ:*/
    float C, html5, php;
    printf("\nMoi nhap diem C: ");
    scanf("%f", &C);
    printf("\nMoi nhap diem html5: ");
    scanf("%f", &html5);
    printf("\nMoi nhap diem php: ");
    scanf("%f", &php);
    float diemTB;
    diemTB = (C + html5 + php) / 3;
    if (diemTB >= 9)
    {
        printf("\nXuat sac");
    }
    else if (diemTB >= 8)
    {
        printf("\nGioi");
    }
    else if (diemTB >= 6.5)
    {
        printf("\nTien tien");
    }
    else if (diemTB >= 5)
    {
        printf("\nTrung Binh");
    }
    else
    {
        printf("\nThi lai!");
    }
    return 0;
}