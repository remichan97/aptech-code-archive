#include <stdio.h>

int main() {
    int n;
    do
    {
        printf("\nMoi ban nhap mot so nguyen duong: ");
        scanf("%d",&n);
    } while (!(0<n && n<1000)); /*! phủ định trong khoảng*/
    /*tách chữ số hàng đơn vị*/
    int donvi;
    donvi=n%10;
    /*tách chữ số hàng chục*
    123 -> 123/10%10*/
    int chuc;
    chuc=n/10%10;
    int tram;
    /*tách chữ số hàng trăm
    5678 ->5678/100%10*/
    tram=n/100%10;
    int nghin;
    /*tách chữ số hàng nghìn
    987123 -> 987123/1000%10*/
    nghin=n/1000%10;
    printf("\nDon vi= %d",donvi);
    printf("\nChuc= %d",chuc);
    printf("\nTram= %d",tram);
    printf("\nNghin= %d",nghin);

    return 0;
}