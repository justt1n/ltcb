#include <stdio.h>

int main()
{
    FILE *fileptr;
    int count_lines = 0;
    char filechar[40], chr;
    scanf("%s", filechar);
    fileptr = fopen(filechar, "r");

    chr = getc(fileptr);
    while (!feof(fileptr))
    {
        chr = getc(fileptr);
        if (chr == '\n')
        {
            count_lines++;
        }
    }
    fclose(fileptr);
    printf("%d", count_lines);
    return 0;
}