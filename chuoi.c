int Compare(char s1[], char s2[])
{

    int i = 0;
    int j = 0;
    int d = 0;
    while (s1[i] != '\0' && s2[j] != '\0')
    {
        d = s1[i] - s2[j];
        if (d == 32 || d == -32 || d == 0)
        { //neu tui no giong nhau thi chay tiep
            i++;
            j++;
        }
        else // deo thi dung
            break;
    }

    if (d > 0 && d != 32)
        return 1;
    if (d < 0 && d != -32)
        return -1;
    else
        return 0;
}
