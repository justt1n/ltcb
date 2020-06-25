#include <stdio.h>
#include <stdlib.h>
void copyOddNumbers(int a[], int n, int b[], int *pM)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1)
        {
            *(b + j) = *(a + i);
            j++;
        }
    }
    *pM = j;
}

void printList(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void getMax(float a[], int n, float *pMaxValue, int *pMaxPos)
{
    *pMaxValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > *pMaxValue)
        {
            *pMaxValue = a[i];
            *pMaxPos = i;
        }
    }
}

int *getSequence(int n, int d)
{
    int *p;
    p = (int *)malloc(4 * n);
    *p = 1;
    for (int i = 1; i < n; i++)
    {
        *(p + i) = *(p + i - 1) + d;
    }
    return p;
}

int main()
{
    int *a;
    int n = 5, d = 2;
    int i;
    a = getSequence(n, d);
    for (i = 0; i <= n - 1; i++)
        printf("%d ", a[i]);
    free(a);
}