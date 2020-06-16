#include <stdio.h>

int readList1d(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    return 0;
}

void bubbleSoft(int a[], int n)
{
    int i, j;
    for (j = 0; j < n; j++)
        for (i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = temp;
            }
        }
    return;
}

int printList1d(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

int main()
{
    int n;
    char abc[100];
    gets(abc);
    scanf("%d", &n);
    int a[n];
    readList1d(a, n);
    printList1d(a, n);
    printf("\n");
    bubbleSoft(a, n);
    printList1d(a, n);
}