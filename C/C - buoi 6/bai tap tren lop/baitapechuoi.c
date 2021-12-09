#include <stdio.h>
#include <string.h>

int main()
{
    char a[50];
    char ch;
    char b[50];
    int i, j, dem, count, inHoa = 0, timKytu = 0, doiXung = 0, soTu = 0;
    float tbc = 0;
    int option;
    do
    {
        printf("\nMoi ban nhap mot chuoi bat ky trong khoang tu 0 den 50 ky tu: ");
        gets(a);
    } while (!(0 < strlen(a) && strlen(a) <= 50));
    while (1)
    {
        printf("\nMoi ban chon mot trong cac chuc nang sau:");
        printf("\n0. Nhap lai mot chuoi khac.");
        printf("\n1. Kiem tra trong chuoi vua nhap co ky so hay khong?");
        printf("\n2. Kiem tra trong chuoi vua nhap co ky tu in hoa khong?");
        printf("\n3. Nhap vao mot ky tu bat ky va kiem tra xem ky tu do co xuat hien trong chuoi khong?");
        printf("\n4. Nhap vao mot chuoi bat ky, kiem tra xem chuoi do co nam trong chuoi ban dau khong? So sanh do dai hai chuoi, va kiem tra xem chuoi vua nhap co lon hon chuoi ban dau khong?");
        printf("\n5. Kiem tra tinh doi xung cua chuoi.");
        printf("\n6. Dem so tu trong chuoi.");
        printf("\n7. Loai bo dau cach o cuoi chuoi.");
        printf("\n8. Loai bo dau cach o dau chuoi.");
        printf("\n9. Dam bao rang giua moi tu cach nhau boi 1 dau cach.");
        printf("\n10. Tinh gia tri trung binh cua tat ca ky tu cua chuoi theo bang thu tu ky tu trong bang ma ASCII");
        printf("\n11. Dem moi ky tu trong chuoi xuat hien bao nhieu lan.");
        printf("\n12. Ket thuc chuong trinh.");
        do
        {
            printf("\nMoi ban chon mot chuc nang: ");
            scanf("%d", &option);
        } while (!(0 <= option && option <= 12));

        switch (option)
        {
        case 0:
        printf("\n===Nhap lai chuoi khac===");
        fflush(stdin);
            do
            {
                printf("\nMoi ban nhap mot chuoi bat ky trong khoang tu 0 den 50 ky tu: ");
                gets(a);
            } while (!(0 < strlen(a) && strlen(a) <= 50));
            break;
        case 1:
            printf("\n===Kiem tra ky so trong chuoi===");
            for (i = 0; i < strlen(a); i++)
            {
                if ('0' <= a[i] && a[i] <= '9')
                {
                    dem += 1;
                }
            }
            if (dem == 0)
            {
                printf("\nChuoi vua nhap khong co ky so nao.");
            }
            else
            {
                printf("\nChuoi vua nhap co ky so.");
            }
            break;
        case 2:
            printf("\n===Kiem tra trong chuoi co chu in hoa hay khong===");
            for (i = 0; i < strlen(a); i++)
            {
                if ('A' <= a[i] && a[i] <= 'Z')
                {
                    inHoa += 1;
                }
            }
            if (inHoa == 0)
            {
                printf("\nChuoi vua nhap khong co chu in hoa.");
            }
            else
            {
                printf("\nChuoi vua nhap co chu in hoa.");
            }
            break;
        case 3:
            printf("\n===Nhap mot ky tu bat ky va kiem tra ky tu do co xuat hien trong chuoi khong===");
            fflush(stdin);
            printf("\nNhap vao mot ky tu de kiem tra: ");
            ch = getchar();
            for (i = 0; i < strlen(a); i++)
            {
                if (strchr(a, ch) != NULL)
                {
                    timKytu += 1;
                }
            }
            if (timKytu == 0)
            {
                printf("\nKy tu vua nhap khong xuat hien trong chuoi.");
            }
            else
            {
                printf("\nKy tu vua nhap xuat hien trong chuoi.");
            }
            break;
        case 4:
            fflush(stdin);
            printf("\nNhap mot chuoi bat ky de thuc hien viec doi chieu va so sanh: ");
            gets(b);
            printf("\n===Kiem tra xem chuoi co nam trong chuoi ban dau khong===");
            if (strstr(a, b) != NULL)
            {
                printf("\nChuoi vua nhap nam trong chuoi ban dau.");
            }
            else
            {
                printf("\nChuoi vua nhap khong nam trong chuoi ban dau.");
            }
            printf("\n===So sanh do dai 2 chuoi===");
            if (strlen(a) > strlen(b))
            {
                printf("\nChuoi ban dau dai hon chuoi nhap vao.");
            }
            else if (strlen(a) < strlen(b))
            {
                printf("\nChuoi nhap vao dai hon chuoi ban dau.");
            }
            else
            {
                printf("\nHai chuoi nay co do dai tuong duong nhau.");
            }
            printf("\n===So sanh chuoi nhap vao co lon hon chuoi ban dau khong===");
            if (strcmp(a, b) > 0)
            {
                printf("\nChuoi ban dau lon hon chuoi nhap vao.");
            }
            else if (strcmp(a, b) < 0)
            {
                printf("\nChuoi nhap vao lon hon chuoi ban dau.");
            }
            else
            {
                printf("\nHai chuoi nay bang nhau");
            }
            break;
        case 5:
            printf("\n===Kiem tra tinh doi xung cua chuoi===");
            for (i = 0; i < strlen(a); i++)
            {
                if (a[i] != a[strlen(a) - 1 - i])
                {
                    doiXung += 1;
                }
            }
            if (doiXung == 0)
            {
                printf("\nChuoi vua nhap la chuoi doi xung.");
            }
            else
            {
                printf("\nChuoi vua nhap khong phai la chuoi doi xung.");
            }
            break;
        case 6:
            printf("\n===Dem so tu trong chuoi===");
            for (i = 0; i < strlen(a) - 1; i++)
            {
                if (a[i] == ' ' && a[i + 1] != ' ')
                {
                    soTu++;
                }
            }
            if (a[0] != ' ')
            {
                soTu++;
            }
            printf("\nChuoi ban dau co %d tu.", soTu);
            break;
        case 7:
            printf("\n===Xoa dau cach o cuoi chuoi===");
            printf("\nChuoi sau khi xoa dau cach o cuoi chuoi:");
            for (i = strlen(a) - 1; i > 0; i--)
            {
                if (a[i] != ' ')
                {
                    a[i + 1] = '\0';
                    break;
                }
            }
            puts(a);
            break;
        case 8:
            printf("\n===Xoa dau cach o dau chuoi===");
            strrev(a);
            for (i = strlen(a); i > 0; i--)
            {
                if (a[i] != ' ')
                {
                    a[i + 1] = '\0';
                    break;
                }
            }
            puts(a);
            break;
        case 9:
            printf("\n===Dam bao chuan dau cach===");
            for (i = 0; i < strlen(a) - 1; i++)
            {
                while (a[i] == ' ' && a[i + 1] == ' ')
                {
                    for (j = i + 1; j < strlen(a) - 1; j++)
                    {
                        a[i] = a[j + 1];
                    }
                    a[strlen(a) - 1] = '\0';
                }
            }
            puts(a);
            break;
        case 10:
            printf("\n===Tinh gia tri trung binh cua tat ca ky tu trong chuoi theo bang ma ASCII===");
            for (i = 0; i < strlen(a); i++)
            {
                tbc += a[i];
            }
            printf("\nTrung binh cong cua cac ky tu: %g", tbc / strlen(a));
            break;
        case 11:
            printf("\n===Dem moi ky tu trong chuoi xuat hien bao nhieu lan===");
            for (i = 0; i < strlen(a); i++)
            {
                count = 0;
                dem = 0;
                for (j = 0; j < i; j++)
                {
                    if (a[j] == a[i])
                    {
                        dem = 1;
                        break;
                    }
                }
                if (dem == 0)
                {
                    for (j = i; j < strlen(a); j++)
                    {
                        if (a[j] == a[i])
                        {
                            count++;
                        }
                    }
                }
                printf("\nKy tu '%c' xuat hien %d lan trong chuoi.", a[i], count);
            }
            break;
        default:
            return 0;
            break;
        }
    }
    return 0;
}