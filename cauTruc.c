#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Point
{
    double X, Y;
};

struct Point readPoint()
{
    struct Point A;
    scanf("%lf%lf", &A.X, &A.Y);
    return A;
}

void printPoint(struct Point A)
{
    printf("(%.3lf, %.3lf)", A.X, A.Y);
}

double distance(struct Point A, struct Point B)
{
    return sqrt(pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2));
}

int equal(struct Point A, struct Point B, double Epsilon)
{
    return distance(A, B) < Epsilon;
}

int isTriangle(struct Point A, struct Point B, struct Point C)
{
    double ab = distance(A, B);
    double ac = distance(A, C);
    double bc = distance(B, C);
    if (ab + bc > ac && ab + ac > bc && ac + bc > ab)
        return 1;
    return 0;
}

struct Rect
{
    struct Point upperP, lowerP;
};

double area(struct Rect A)
{
    struct Point tmp = {A.upperP.X, A.lowerP.Y};
    double length = distance(A.upperP, tmp);
    double wide = distance(A.lowerP, tmp);
    return length * wide;
}

int isIn(struct Point M, struct Rect r)
{
    struct Point Bx = {r.lowerP.X, 0};
    struct Point Ax = {r.upperP.X, 0};
    struct Point Ay = {0, r.upperP.Y};
    struct Point By = {0, r.lowerP.Y};
    struct Point Mx = {M.X, 0};
    struct Point My = {0, M.Y};

    double X = (Mx.X - Ax.X) / (Bx.X - Ax.X);
    double Y = (My.Y - Ay.Y) / (By.Y - Ay.Y);
    if (0 <= X && X <= 1 && 0 <= Y && X <= 1)
        return 1;
    return 0;
}

struct PhanSo
{
    int TuSo;
    int MauSo;
};

struct PhanSo nhapPhanSo()
{
    struct PhanSo A;
    scanf("%d%d", &A.TuSo, &A.MauSo);
    return A;
}

void inPhanSo(struct PhanSo A)
{
    printf("%d/%d\n", A.TuSo, A.MauSo);
}

int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

void chuanhoa(struct PhanSo *pa)
{
    int tmp = pa->TuSo;
    pa->TuSo = pa->TuSo / UCLN(tmp, pa->MauSo);
    pa->MauSo = pa->MauSo / UCLN(tmp, pa->MauSo);
}

void cong(struct PhanSo A, struct PhanSo B, struct PhanSo *pC)
{
    //pC = (struct Point *)malloc(sizeof(struct Point));
    pC->TuSo = A.TuSo * B.MauSo + B.TuSo * A.MauSo;
    pC->MauSo = A.MauSo * B.MauSo;
    chuanhoa(pC);
}

void nhan(struct PhanSo A, struct PhanSo B, struct PhanSo *pC)
{
    pC->TuSo = A.TuSo * B.TuSo;
    pC->MauSo = A.MauSo * B.MauSo;
    chuanhoa(pC);
}

typedef struct
{
    double Real, Image;
} Complex;

Complex readComplex()
{
    Complex A;
    scanf("%lf%lf", &A.Real, &A.Image);
    return A;
}

void printComplex(Complex A)
{
    printf("%.3lf + i%.3lf\n", A.Real, A.Image);
}

void add(Complex A, Complex B, Complex *pC)
{
    pC->Real = A.Real + B.Real;
    pC->Image = A.Image + B.Image;
}

// DANH SACH SV
typedef struct
{
    char *HoTen;
    float LT, TH;
    char *DiemChu;
} SinhVien;

SinhVien nhapSV()
{
    SinhVien a;
    a.HoTen = (char *)malloc(500);
    fgets(a.HoTen, 500, stdin);
    int i = 0;
    while (*(a.HoTen + i) != '\0')
    {
        if (*(a.HoTen + i) == '\n')
            a.HoTen[i] = '\0';
        i++;
    }
    scanf("%f%f\n", &a.LT, &a.TH);
    return a;
}

void inSV(SinhVien a)
{
    float tong = (a.TH + a.LT) / 2.0;
    a.DiemChu = (char *)malloc(4);
    if (tong >= 9)
        a.DiemChu = "A";
    else if (tong >= 8)
        a.DiemChu = "B";
    else if (tong >= 7)
        a.DiemChu = "B+";
    else if (tong >= 6)
        a.DiemChu = "C";
    else if (tong >= 5)
        a.DiemChu = "C+";
    else if (tong >= 4.5)
        a.DiemChu = "D";
    else if (tong >= 4.0)
        a.DiemChu = "D+";
    else
        a.DiemChu = "F";
    printf("%s %.3f %.3f %s", a.HoTen, a.LT, a.TH, a.DiemChu);
}

void nhapDS(SinhVien **pL, int n)
{
    *pL = (SinhVien *)malloc(n * sizeof(SinhVien));
    for (int i = 0; i < n; i++)
        (*pL)[i] = nhapSV();
}

void inDS(SinhVien *L, int n)
{
    for (int i = 0; i < n; i++)
    {
        float tong = ((L + i)->TH + (L + i)->LT);
        (L + i)->DiemChu = (char *)malloc(4);
        if (tong >= 9)
            (L + i)->DiemChu = "A";
        else if (tong >= 8)
            (L + i)->DiemChu = "B";
        else if (tong >= 7)
            (L + i)->DiemChu = "B+";
        else if (tong >= 6)
            (L + i)->DiemChu = "C";
        else if (tong >= 5)
            (L + i)->DiemChu = "C+";
        else if (tong >= 4.5)
            (L + i)->DiemChu = "D";
        else if (tong >= 4.0)
            (L + i)->DiemChu = "D+";
        else
            (L + i)->DiemChu = "F";
        printf("%s %.3f %.3f %s\n", (L + i)->HoTen, (L + i)->LT, (L + i)->TH, (L + i)->DiemChu);
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// void sapXepSV(SinhVien *L, int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if ((*L)[1] >= (*L)[j + 1])
//         }
//     }
// }

/*DON THUC
struct DonThuc
{
    float he_so;
    int bac;
};

void InDonThuc(struct DonThuc a)
{
    printf("%.2fx^%d\n", a.he_so, a.bac);
}
*/

int main()
{

    return 0;
}