#include <stdio.h>
#define SOI 100 
int main() {
    /*Hằng: Là dữ liệu - là giá trị không đổi trong quá trình chạy chương trình.
    Khai bóa hằng:
    C1: #define tên_hằng giá_trị;
    C2: const kiểu_dữ_liệu tên_hằng = giá_trị;
    */
    printf("\nDo soi= %d",SOI);
    const int DONG = 0;
    printf("\nDo dong= %d",DONG);
    return 0;
}