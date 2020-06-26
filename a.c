#include <stdio.h>
#include <math.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int x;
    scanf("%d", &x);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == x)
            {
                printf("(%d, %d) ", i, j);
                count++;
            }
    if (count != 0)
        printf("\n");
    printf("%d", count);
    return 0;
}