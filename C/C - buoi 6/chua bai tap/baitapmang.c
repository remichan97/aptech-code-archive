#include <stdio.h>

int main()
{
    int N;
    float arr[49];
    int i;
    do
    {
        printf("\nMoi nhap so luong phan tu N: ");
        scanf("%d", &N);
    } while (!(0 < N && N < 50));
    printf("\nMoi nhap lieu cho mang:");
    for (i = 0; i < N; i++)
    {
        printf("\nPhan tu thu %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    //sắp xếp tăng dần: 1 3 2 5 4 -> 1 2 3 4 5
    //lần 1: 1 3 2 5 4
    //lần 2: 1 2 3 5 4
    //lần 3: 1 2 3 5 4
    //lần 4: 1 2 3 4 5
    //arr[0] arr[1] arr[2] arr[3] arr[4]
    int j;
    float tg;
    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                tg = arr[i];
                arr[i] = arr[j];
                arr[j] = tg;
            }
        }
    }
    printf("\nDay so sap xep tang dan:");
    for (i = 0; i < N; i++)
    {
        printf("\narr[%d]= %g", i, arr[i]);
    }
    //Sắp xếp giảm dần (tương tự như trên):
    //1 3 2 5 4 -> 5 4 3 2 1
    //3 1 2 5 4
    //5 1 2 3 4
    //5 2 1 3 4
    //5 3 1 2 4
    //5 4 1 2 3
    //5 4 3 1 2
    //5 4 3 2 1
    //Tìm và hiển thị những số > TBC;
    float tbc = 0;
    for (i = 0; i < N; i++)
    {
        tbc += arr[i];
    }
    tbc /= N;
    int timThay = 0;
    printf("\nTBC = %g", tbc);
    printf("\nNhung so lon hon TBC:");
    for (i = 0; i < N; i++)
    {
        if (arr[i] > tbc)
        {
            printf("\narr[%d]= %g", i, arr[i]);
            timThay = 1;
        }
    }
    if (!(timThay))
    {
        printf("\nKhong tim thay phan tu nao.");
    }
    
    return 0;
}