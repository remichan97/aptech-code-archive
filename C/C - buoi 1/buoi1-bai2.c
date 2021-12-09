#include <stdio.h>

int main() {
    //input: scanf();
    //C là ngôn ngữ lập trình định kiểu -> Dữ liệu được chia thành các kiểu khác nhau.
    /*Kiểu dữ liệu cơ sở: int (interger - số nguyên), float (thực), double (số thực, nhưng có thể lưu được số lớn), char (ký tự), void (dùng cho hàm)
    từ kiểu char -> kiểu chuỗi*/
    //dùng biến để lưu trữ thông tin.
    //khai báo biến: Khai báo 1 vùng nhớ trong ổ đĩa
    //cú pháp khai báo biến: kiểu_dữ_liệu tên_biến;
    //ví dụ:
    int number;
    /*lưu ý: việc đặt tên cho biến là do lập trình viên thực hiện, nhưng phải tuân thủ quy tắc đặt tên chung như sau:
    - Không có dâu cách
    - Không có chữ số ở đầu tên (1st là sai)
    - Không chứa phép toán (+ - * / ...)
    */
    float number1=10.5; //phép gán (lưu)
    char c='A';
    char hoTen[30]; //biến chuỗi họ tên, chứa tối đa 30 ký tự. Chuỗi phải nẳm trong cặp nháy kép ""
    printf("\nMoi ban nhap ho ten: ");
    /*scanf("%s",&hoTen);*/ /*f = format (in thông tin có định dạng)
    int: %d
    char: %c
    float: %f
    double: %lf
    chuỗi: %s*/
    gets(hoTen);
    printf("\nHo ten cua ban la: %s",hoTen);
    return 0;
}