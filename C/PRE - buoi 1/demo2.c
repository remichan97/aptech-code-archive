#include <stdio.h>
#include <string.h>

int main() {
    /*chuyển sang dùng biến (variable) để lưu dữ liệu*/
    /*Các kiểu dữ liệu cơ bản:*/
    /*int: lưu số nguyên*/
    /*char: lưu ký tự*/
    /*float: lưu số thực, với số thập phân thì dùng dấu chấm*/
    /*double: tương tự như trên, nhưng lưu với số lớn*/
    /*cú pháp khai báo biến: kiểu_dữ_liệu tên_biến; or kiểu_dữ_liêu tên_biến=giá_trị */
    /*ví dụ:*/
    int number1; /*int: 2B (16b)*/
    float number2=9.8; /*float: 4B*/
    /*phép toán =: phép gán (lưu) => lưu giá trị cho biến*/
    /*khai báo biến để yêu cầu hệ thống cấp vùng bộ nhớ để lưu dữ liệu*/
    /*printf("\nMoi ban nhap number1:");*/
    /*scanf("%d",&number1);*/ /*& dùng để lấy địa chỉ biến*/
    /*printf("\nSau khi nhap, number1=%d",number1);*/
    char name[5];
    do /*chạy đoạn code ở đây trước*/
    {
    printf("\nMoi ban nhap ten:");
    gets(name);
    } while ((strlen(name)<5));/*sau đó kiểm tra điều kiện ở đây*/ /*vòng lặp có điều kiện*/
    printf("\nSau khi nhap, ten la: %s",name); /*%s là định dạng dành cho chuỗi*/
    return 0;
}