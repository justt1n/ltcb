#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nonEmpty(char ch[])
{
    int i = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] != ' ')
            return 1;
    }
    return 0;
}

int main()
{
    char ch[100];
    char name[40];
    scanf("%s", name);
    FILE *file = fopen(name, "r");
    if (file)
    {
        while (fgets(ch, 100, file) != NULL)
            if (ch != '\0')
                printf("%s", ch);
        fclose(file);
    }
    return 0;
}