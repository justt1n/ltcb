#include <stdio.h>

int ReadList(int a[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    return 0;
}

void bubbleSort(int a[], int n)
{
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
        {
            if (a[i] > a[i + 1])
            {
                int tmp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = tmp;
            }
        }
    return;
}

int printfList(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    ReadList(a, n);
    printfList(a, n);
    printf("\n");
    bubbleSort(a, n);
    printfList(a, n);
}