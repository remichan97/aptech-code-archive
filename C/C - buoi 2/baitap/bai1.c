#include <stdio.h>

int main() {
    int N;
    printf("\nNhap vao mot so bat ky trong khoang tu 0 den 100: ");
    scanf("%d",&N);
    while (N < 0 && N > 100)
    {
        printf("\nKhong hop le.");
        printf("\nVui long nhap mot so khac: ");
        scanf("%d",&N);
    }  
    printf("\nSo ban vua nhap la: %d",N);
    
    return 0;
}