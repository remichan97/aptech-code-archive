#include <stdio.h>

int main() {
    int n = 123;
    float f = 12.34;
    printf("\n%10d", n); //dành ra một khoảng nhất định (ở đây là 10) để in ra giá trị bất kỳ, thường sẽ canh phải. (số âm sẽ canh trái)
    printf("\n%.3f", f); //.n là độ chính xác của số thực, phần nguyên để dành ra một khoảng nhất định để in ra giá trị bất kỳ, nếu ít quá sẽ tự động để cho đủ hiển thị.
    return 0;
}