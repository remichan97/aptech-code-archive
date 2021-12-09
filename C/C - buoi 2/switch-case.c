#include <stdio.h>

int main()
{
    /*switch-case: cặp hàm điều kiện chỉ dành cho hằng số nguyên và hằng ký tự.
    cú pháp: */
    /*switch (biểu_thức)
    {
    case giá_trị 1:
        lệnh 1;
        break;
    case giá_trị 2:
        lệnh 2;
        break;
    default:
        lệnh 3;
        break;
    }*/
    //cú pháp rút gọn:
    /*switch (biểu_thức)
    {
    case giá_trị1: case giá_trị2:... case gía_trị_n: (hoặc giá trị này hoặc giá trị kia)
        lệnh_1;
        break;
    
    default:
        break;
    }*/
    //lưu ý: không bắt buộc phải có default.
    //ví dụ áp dụng: nhập vào một tháng bất kỳ rồi kiểm tra xem tháng đó có bao nhiêu ngày?
    //Gợi ý: tháng 1,3,5,7,8,10,12 có 31 ngày
    //các tháng 4,6,9,11 có 30 ngày.
    //riêng tháng 2 mà năm nhuận là 29 ngày, năm thường thì có 28 ngày.
    //năm nhuận: chia hết cho 4 nhưng không chia hết cho 100, hoặc chia hết cho 400.
    int month, year;
    do
    {
        printf("\nNhap mot thang bat ky: ");
        scanf("%d", &month);
    } while (!(month > 0 && month <= 12));
    switch (month)
    {
    case 2:
        printf("\nNhap vao mot nam bat ky: ");
        scanf("%d", &year);
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            printf("\nThang 2 nam do co 29 ngay.");
        }
        else
        {
            printf("\nThang 2 nam do co 28 ngay.");
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("\nThang do co 30 ngay.");
        break;
    default:
        printf("\nThang do co 31 ngay.");
        break;
    }
    return 0;
}