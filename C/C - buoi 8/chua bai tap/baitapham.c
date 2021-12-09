#include<stdio.h>

///2.
///int i;///Biến global
float nhapLieu(int i){
    float number;///Biến local - chỉ dùng được trong hàm
    ///chứa nó
    printf("\nNhap number%d: ",i);///static
    scanf("%f",&number);
    return number;
    ///...
}

///3.
void tinhTong(float number1,float number2){
    printf("\n%g + %g = %g",number1,number2,number1+number2);
}

///4.
void tinhHieu(float number1,float number2){
    printf("\n%g - %g = %g",number1,number2,number1-number2);
}

///5.
void tinhNhan(float number1,float number2){
    printf("\n%g * %g = %g",number1,number2,number1*number2);
}

///6.
void tinhChia(float number1,float number2){
    if(number2==0){
        printf("\nKhong chia duoc");
        printf(" vi mau so =0");
    }
    else{
        printf("\n%g / %g = %g",number1,number2,number1/number2);
    }
}

void tinhToan(float number1,float number2,char phepToan){
    double ketQua;
    printf("\n%g %c %g = ",number1,phepToan,number2);
    if(phepToan=='+'){
        ketQua=number1+number2;
    }else if(phepToan=='-'){
        ketQua=number1-number2;
    }else if(phepToan=='*'){
        ketQua=number1*number2;
    }else if(phepToan=='/'){
        if(number2==0){
            printf("Khong chia duoc vi mau so =0");
            return;
        }else{
            ketQua=number1/number2;
        }
    }
    printf("%g",ketQua);
}

float min(float number1,float number2){
    if(number1>number2){
        return number1;
    }
    return number2;
//    return number1>number2?number1:number2;
}

int xacDinhNguyenDuong(float number1,float number2){
    if((number1==(int)number1 && number1>0) && (number2==(int)number2 && number2>0)){
        return 1;
    }
    return 0;
}

///7.
int timUocSoChungLonNhat(float number1,float number2){
    //int ucln;
    int i;///60 120
    if(xacDinhNguyenDuong(number1,number2)==1){
        for(i=min(number1,number2); i>=1; i--){
            if((int)number1%i==0 && (int)number2%i==0){
                return i;
                //printf("\nUoc chung lon nhat cua %g va %g la %d",number1,number2,i);
                //break;
                //ucln=i;
            }
        }
        //printf("\nUoc chung lon nhat cua %g va %g la %d",number1,number2,i);
    }else{
        return 0;
        ///printf("\nKhong co uoc so chung giua 2 so %g va %g",number1,number2);
    }
}

///8.
void timBoiChungNhoNhat(float number1,float number2){
    if(xacDinhNguyenDuong(number1,number2)==1){
        printf("\nBoi chung nho nhat cua %g va %g la %g",number1,number2,number1*number2/timUocSoChungLonNhat(number1,number2));
        ///60 90: 180 (30x2x3=30x(60/30)x(90/30)=30x60x90/(30x30)=60x90/30) 360 540 720...
    }else{
        printf("\nKhong co boi so chung giua 2 so %g va %g",number1,number2);
    }
}

///0.
void menu(){
    printf("\n1. Nhap 2 so bat ky");
    printf("\n2. Tinh cong");
    printf("\n3. Tinh tru");
    printf("\n4. Tinh nhan");
    printf("\n5. Tinh chia");
    printf("\n6. Tim uoc chung lon nhat");
    printf("\n7. Tim boi chung nho nhat");
    printf("\n8. Thoat");
}

///1.
int main(){

    float number1, number2;
    int ucln;
    int option;
    int chon1=0;
    menu();
    while(1){
        printf("\nMoi chon 1 muc: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                chon1=1;
                number1=nhapLieu(1);
                number2=nhapLieu(2);
                break;
            case 2:
                if(chon1==0){
                    printf("\nBan phai chon 1 truoc!");
                    continue;
                }
                tinhToan(number1,number2,'+');
                break;
            case 3:
                if(chon1==0){
                    printf("\nBan phai chon 1 truoc!");
                    continue;
                }
                tinhToan(number1,number2,'-');
                break;
            case 4:
                if(chon1==0){
                    printf("\nBan phai chon 1 truoc!");
                    continue;
                }
                tinhToan(number1,number2,'*');
                break;
            case 5:
                if(chon1==0){
                    printf("\nBan phai chon 1 truoc!");
                    continue;
                }
                tinhToan(number1,number2,'/');
                break;
            case 6:
                if(chon1==0){
                    printf("\nBan phai chon 1 truoc!");
                    continue;
                }
                ucln=timUocSoChungLonNhat(number1,number2);
                if(ucln==0){
                    printf("\nKhong co uoc so chung giua 2 so %g va %g",number1,number2);
                }else{
                    printf("\nUoc chung lon nhat cua %g va %g la %d",number1,number2,ucln);
                }
                break;
            case 7:
                if(chon1==0){
                    printf("\nBan phai chon 1 truoc!");
                    continue;
                }
                timBoiChungNhoNhat(number1,number2);
                break;
            case 8: return;
        }
    }
//    printf("\nnumber1=%g",number1);
//    printf("\nnumber2=%g",number2);
//    tinhTong(number1,number2);
//    tinhHieu(number1,number2);
//    tinhNhan(number1,number2);
//    tinhChia(number1,number2);

    return 0;
}