#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void printPrimeNumbers(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }
}

int main()
{
    printPrimeNumbers(2, 10);
}