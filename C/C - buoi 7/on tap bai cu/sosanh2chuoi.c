#include <stdio.h>
#include <string.h>

int main() {
    //so sánh 2 chuỗi: Dựa trên thứ tự ký tự trong bảng mã ASCII.
    //Cách thức so sánh: Bắt đầu từ bên trái của 2 chuỗi, lấy từng cặp ký tự của hai chuôi đem so sánh với nhau. Nếu giống nhau thì lấy cặp ký tuwj tiếp theo để so sánh. Việc so sánh sẽ dừng lại khi cặp ký tự là khác nhau, và đưa ra kết luận: Ký tự nào lớn hơn thì chuỗi đó sẽ lớn hơn.
    //Ví dụ "abcd1234" > "abc1234567890" vì "d" > "1"
    //Sử dụng hàm strcmp() để so sánh 2 chuỗi.
    //strcmp(S1,S2); : nếu trả về số > 0 thì S1 > S2, trả về 0 thì hai chuỗi S1 == S2, trả về số < 0 thì S1 < S2.
    //Ví dụ:
    printf("\n%d", strcmp("abcd1234", "abc1234567890"));
    return 0;
}