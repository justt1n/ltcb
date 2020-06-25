#include <stdio.h>
#include <string.h>
void mystrcpy(char *s1, char *s2)
{
    for (int i = 0; i < strlen(s1); i++)
    {
        *(s2 + i) = *(s1 + i);
    }
}

int main()
{
<<<<<<< HEAD
    char c[100];
    mystrcpy("Hello World", c);
    printf("%s", c);
=======
    int n;
    char abc[100];
    gets(abc);
    scanf("%d", &n);
    int a[n];
    readList1d(a, n);
    printList1d(a, n);
    printf("\n");
    bubbleSoft(a, n);
    printList1d(a, n);
>>>>>>> 9b117e0e06555ebf0bf5aee56e35848dbf0644e7
}