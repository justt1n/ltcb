#include <stdio.h>

int main()
{
    char a[100];
    fgets(a, 100, stdin);
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
    FILE *file = fopen(a, "r");
    int count = 0;
    while
}
