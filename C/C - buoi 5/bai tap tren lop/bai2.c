
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int i, j;
    float N[49];
    float tong, tbCong, soSanh, trungGian;
    float chinhPhuong;
    float max, min, maxChan, minLe;
    int option;
    printf("\nMoi ban chon mot trong cac chuc nang sau:");
    printf("\n1. Nhap mot so nguyen N (0 < N < 50).");
    printf("\n2. Nhap mot mang gom N so thuc.");
    printf("\n3. Tim so lon nhat trong mang.");
    printf("\n4. Tim so nho nhat trong mang.");
    printf("\n5. Tim so duong chan lon nhat trong mang.");
    printf("\n6. Tim so le am nho nhat trong mang.");
    printf("\n7. Tim cac so chinh phuong trong mang.");
    printf("\n8. Tinh tong mang.");
    printf("\n9. Tinh trung binh cong cac phan tu mang.");
    printf("\n10. Tim nhung phan tu lon hon trung binh cong.");
    printf("\n11. Sap xep theo thu tu tang dan cac thu tu trong mang.");
    printf("\n12. Sap xep theo thu tu giam dan cac thanh phan trong mang.");
    printf("\n13. Ket thuc chuong trinh.");
    while (1)
    {
        printf("\nNhap mot so tuong ung voi lua chon cua ban: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            do
            {
                printf("\nMoi ban nhap mot so N trong khoang 0 < N < 50: ");
                scanf("%d", &n);
            } while (!(n > 0 && n < 50));
            break;
        case 2:
            for (i = 0; i < n; i++)
            {
                printf("\nMoi nhap phan tu thu %d cua mang: ", i + 1);
                scanf("%f", &N[i]);
            }
            break;
        case 3:
            max = N[0];
            for (i = 1; i < n; i++)
            {
                if (max < N[i])
                {
                    max = N[i];
                }
            }
            printf("\nSo lon nhat trong mang vua nhap la: %g", max);
            break;
        case 4:
            min = N[0];
            for (i = 1; i < n; i++)
            {
                if (min > N[i])
                {
                    min = N[i];
                }
            }
            printf("\nSo nho nhat trong mang vua nhap la: %g", min);
            break;
        case 5:
            maxChan = N[0];
            for (i = 0; i < n; i++)
            {
                if ((int)N[i] % 2 == 0 && N[i] > 0 && maxChan < N[i])
                {
                    maxChan = N[i];
                }
            }
            printf("\nSo chan duong lon nhat trong mang la: %g", maxChan);
            break;
        case 6:
            minLe = N[0];
            for (i = 0; i < n; i++)
            {
                if ((int)N[i] % 2 != 0 && N[i] < 0 && minLe > N[i])
                {
                    minLe = N[i];
                    printf("\nSo le aam nho nhat trong mang la :%g", minLe);
                }
                else
                {
                    printf("\nMang nay khong co so am nao.");
                    break;
                }
            }
            break;
        case 7:
            for (i = 0; i < n; i++)
            {
                if ((int)N[i] > 0 && (sqrt(N[i]) == (int)sqrt(N[i])))
                {
                    chinhPhuong = N[i];
                }
                else
                {
                    printf("\nMang nay khong co so chinh phuong nao.");
                    break;
                }
                printf("\nCac so chinh phuong trong mang la: %g", chinhPhuong);
            }
            break;
        case 8:
            tong = 0;
            for (i = 0; i < n; i++)
            {
                tong = tong + N[i];
            }
            printf("\nTong cua cac so trong mang la: %g", tong);
            break;
        case 9:
            for (i = 0; i < n; i++)
            {
                tbCong += N[i];
            }
            printf("\nTrung binh cong cua cac so trong mang la: %g", tbCong / n);
            break;
        case 10:
            for (i = 0; i < n; i++)
            {
                tbCong += N[i];
            }
            tbCong = tbCong / n;
            for (i = 0; i < n; i++)
            {
                if (N[i] > tbCong)
                {
                    soSanh = N[i];
                    printf("\nCac so lon hon trung binh cong cua mang la: %g", soSanh);
                    break;
                }
                else
                {
                    printf("\nKhong co so nao trong mang thoa man yeu cau.");
                    break;
                }
            }
            printf("hello world");
            break;
        case 11:
            for (i = 0; i < n - 1; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (N[i] > N[j])
                    {
                        trungGian = N[i];
                        N[i] = N[j];
                        N[j] = trungGian;
                    }
                }
            }
            printf("\nMang da sap xep tang dan la: ");
            for (i = 0; i < n; i++)
            {
                printf("%g ", N[i]);
            }
            break;
        case 12:
            for (i = 0; i < n - 1; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (N[i] < N[j])
                    {
                        trungGian = N[i];
                        N[i] = N[j];
                        N[j] = trungGian;
                    }
                }
            }
            printf("\nMang da sap xep giam dan la: ");
            for (i = 0; i < n; i++)
            {
                printf("%g ", N[i]);
            }
            break;
        default:
            return 0;
            break;
        }
    }

    return 0;
}