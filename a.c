#include <stdio.h>
#include <math.h>
int LCM(int a, int b)
{
    a = abs(a);
    b = abs(b);
    int max = b;
    if (a > b)
        max = a;
    for (int i = max; i < a * b; i++)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return a * b;
}
int lmz()
{
    return 0;
}
//test

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", LCM(a, b));
    return 0;
}