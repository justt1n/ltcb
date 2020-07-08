#include <stdio.h>

long long Factorial2(int n)
{
    long long s = 1;
    if (n % 2 == 0)
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
                s *= i;
        }
    else
        for (int i = 0; i <= n; i++)
        {
            if (i % 2 == 1)
                s *= i;
        }
    return s;
}

int main()
{
    for (int i = 1; i <= 25; i++)
        printf("%lld\n", Factorial2(i));
    return 0;
}