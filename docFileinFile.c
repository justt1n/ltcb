#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int c;
    char name[40];
    scanf("%s", name);
    FILE *file = fopen(name, "r");
    if (file)
    {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    return 0;
}