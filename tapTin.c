#include <stdio.h>
typedef struct
{
    char HoTen[50];
    float ly, hoa, toan;
} SinhVien;

int main()
{
    char a[100];
    //scanf("%s", &a);
    fgets(a, 50, stdin);
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == '\n')
        {
            a[i] = '\0';
            break;
        }
        i++;
    }
    int n;
    FILE *file = fopen(a, "r");
    fscanf(file, "%d\n", &n);
    SinhVien sv[100];
    for (int i = 0; i < n; i++)
    {
        fgets(sv[i].HoTen, 50, file);
        fscanf(file, "%f%f%f\n", &sv[i].toan, &sv[i].ly, &sv[i].hoa);
    }
    printf("Toan |Vat ly |Hoa hoc |Ho va  ten\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%5.2f|%5.2f  |%5.2f   |%s", sv[i].toan, sv[i].ly, sv[i].hoa, sv[i].HoTen);
    }
    printf("Tong so: %d", n);
    return 0;
}