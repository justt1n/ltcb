#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete (char s[90], int vitrixoa)
{
    int n = strlen(s);
    for (int i = vitrixoa; i < n; i++)
        s[i] = s[i + 1];
    s[n - 1] = '\0';
}

void delSpace(char *s)
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            delete (s, i);
            i--;
        }
    if (s[0] == ' ')
        delete (s, 0);
    if (s[strlen(s) - 1] == ' ')
        delete (s, strlen(s) - 1);
}

int main()
{
    char name[40];
    scanf("%s", name);
    FILE *file = fopen(name, "r");
    char c[100];
    if (file)
    {
        while ((fgets(c, 100, file)) != NULL)
        {
            delSpace(c);
            if (c == "")
                printf("%s", c);
        }

        fclose(file);
    }
    return 0;
}