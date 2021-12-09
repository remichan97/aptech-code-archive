#include <stdio.h>

int main() {
    /*phép toán
    phép toán số học: + - * / (chia nguyên) % (chia lấy phần dư) ++ (tăng 1 đơn vị) -- (giảm 1 đơn vị) = (phép gán, lưu)
    ví dụ 9/5 => 1 (chia nguyên chỉ xảy ra khi cả tử và mẫu đều là số nguyên)
    9%5 => 4
    9.0/5 => 1.8
    9/5.0 => 1.8
    kiểu kí tự:
    int -> %d
    char -> %c  dùng khi biến chỉ chứa 1 kí tự
    char* -> %s dùng khi biến là chuỗi
    float -> %f
    double -> %lf
    */
    /*printf("\n%d",a++); printf("\n%d",++a); viết trc biến thì sẽ tăng ngay lập tức, viết sau thì khi in ra vẫn sẽ lấy kết quả trước đó nhưng sẽ tăng lên sau khi kết thúc lệnh*/
    int a=9,b=5;
    int y= a+b,x =a-b;
    printf("\n%d+%d=%d",a,b,y);
    printf("\n%d-%d=%d",a,b,x);
    return 0;
}