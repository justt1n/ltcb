#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dem dong tren tap tin

int countLines(FILE *a)
{
    char ch[100];
    int count = 0;
    while (fgets(ch, sizeof(ch), a) != NULL)
    {
        count++;
    }
    return count;
}

int main()
{
    char name[40];
    scanf("%s", name);
    FILE *file = fopen(name, "r");
    printf("%d", countLines(file));
    fclose(file);
    return 0;
}