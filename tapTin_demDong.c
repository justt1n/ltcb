#include <stdio.h>

int main()
{
    char a[10], ch;
    fgets(a, 10, stdin);
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
    ch = fgetc(file);
    while (ch != EOF)
    {
        {
            if (ch == '\n')
                count++;
            ch = fgetc(file);
        }
    }
    if (ch != ' ')
        count++;

    fclose(file);
    printf("%d", count);
    return 0;
}
