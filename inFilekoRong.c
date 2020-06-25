#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
// int nonEmpty(char ch[])
// {
//     int i = 0;
//     while (ch[i] != '\0')
//     {
//         if (ch[i] != ' ')
//             return 1;
//     }
//     return 0;
// }
=======
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
>>>>>>> 9b117e0e06555ebf0bf5aee56e35848dbf0644e7

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