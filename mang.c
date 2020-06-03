#include <stdio.h>
/* Tam giac pascal

int main(){
    int m;
    scanf("%d", &m);
    long long A[m][m]; 
    long long int n, k; 
    for(n=0; n<m; n++)
        for(k=0; k<=n; k++){
            if(k==0 || k==n) 
                A[n][k]=1; 
            else A[n][k] = A[n-1][k-1] + A[n-1][k];
        }
    for(n=0; n<m; n++){ 
        for(k=0; k<=n; k++) 
            printf("%lld ", A[n][k]); 
        printf("\n");
    } 
    return 0;
} 

*/

void readList2d(int a[][4], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    return;
}

void printList2d(int a[][4], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return;
}

void readList1d(int a[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    return;
}

void printList1d(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return;
}

int locate(int x, int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return n;
}

int tongBinhPhuong(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i] * a[i];
    }
    return s;
}

int tong(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
    }
    return s;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    readList1d(a, n);
    printf("%d\n", tong(a, n));
    printList1d(a, n);
    return 0;
}
