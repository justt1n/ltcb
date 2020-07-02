#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define MAX_M 100
#define MAX_N 100
typedef struct
{
    int m, n;
    int A[MAX_M][MAX_N];
    int r, c;
} State;

void init_state(State *S, char fname[])
{
    FILE *f = fopen(fname, "r");
    fscanf(f, "%d %d", &S->m, &S->n);
    for (int i = 0; i < S->m; i++)
    {
        for (int j = 0; j < S->n; j++)
        {
            fscanf(f, "%d", &S->A[i][j]);
        }
    }
    fscanf(f, "%d %d", &S->r, &S->c);
}

void print_state(State S)
{
    for (int i = 0; i < S.m; i++)
    {
        for (int j = 0; j < S.n; j++)
        {
            if (i == S.r && j == S.c)
            {
                printf(".. ");
            }
            else
            {
                printf("%2d ", S.A[i][j]);
            }
        }
        printf("\n");
    }
    printf("%d %d\n", S.r, S.c);
}

int is_finished(State S)
{
    for (int i = 0; i < S.m; i++)
    {
        for (int j = 0; j < S.n; j++)
        {
            if (S.A[i][j] != i * S.n + j + 1)
                return 0;
        }
    }
    return 1;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int up(State S, State *N)
{
    if (S.r == 0)
        return 0;
    else if (S.r > 0)
    {
        swap(&S.A[S.r][S.c], &S.A[S.r - 1][S.c]);
        S.r--;
        N->m = S.m;
        N->n = S.n;
        for (int i = 0; i < S.m; i++)
            for (int j = 0; j < S.n; j++)
                N->A[i][j] = S.A[i][j];
        N->r = S.r;
        N->c = S.c;
    }
    return 1;
}

int down(State S, State *N)
{
    if (S.r == S.m - 1)
        return 0;
    else if (S.r < S.m)
    {
        swap(&S.A[S.r][S.c], &S.A[S.r + 1][S.c]);
        S.r++;
        N->m = S.m;
        N->n = S.n;
        for (int i = 0; i < S.m; i++)
            for (int j = 0; j < S.n; j++)
                N->A[i][j] = S.A[i][j];
        N->r = S.r;
        N->c = S.c;
    }
    return 1;
}

int left(State S, State *N)
{
    if (S.c == 0)
        return 0;
    else if (S.c > 0)
    {
        swap(&S.A[S.r][S.c], &S.A[S.r][S.c - 1]);
        S.c--;
        N->m = S.m;
        N->n = S.n;
        for (int i = 0; i < S.m; i++)
            for (int j = 0; j < S.n; j++)
                N->A[i][j] = S.A[i][j];
        N->r = S.r;
        N->c = S.c;
    }
    return 1;
}

int right(State S, State *N)
{
    if (S.c == S.n - 1)
        return 0;
    else if (S.c < S.n)
    {
        swap(&S.A[S.r][S.c], &S.A[S.r][S.c + 1]);
        S.c++;
        N->m = S.m;
        N->n = S.n;
        for (int i = 0; i < S.m; i++)
            for (int j = 0; j < S.n; j++)
                N->A[i][j] = S.A[i][j];
        N->r = S.r;
        N->c = S.c;
    }
    return 1;
}

int main()
{
    State S, N;
    char fname[500];
    fgets(fname, 500, stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n')
    {
        len--;
        fname[len] = '\0';
    }
    init_state(&S, fname);
    system("cls");
    print_state(S);
    while (is_finished(S) != 1)
    {
        char cmd;
        cmd = getch();
        system("cls");
        if (cmd == 72)
        {
            if (up(S, &N))
            {
                up(S, &N);
                S = N;
            }
            else
                printf("Illegal move.\n");
        }
        else if (cmd == 80)
        {
            if (down(S, &N))
            {
                down(S, &N);
                S = N;
            }
            else
                printf("Illegal move.\n");
        }
        else if (cmd == 75)
        {
            if (left(S, &N))
            {
                left(S, &N);
                S = N;
            }
            else
                printf("Illegal move.\n");
        }
        else if (cmd == 77)
        {
            if (right(S, &N))
            {
                right(S, &N);
                S = N;
            }
            else
                printf("Illegal move.\n");
        }
        else if (cmd == 9)
        {
            printf("You lose!");
            return 0;
        }
        else
        {
            printf("Unknown command, please press the arrow key on keyboard to solve or press tab to exit\n");
        }

        print_state(S);
    }

    printf("You win!\n");
    getchar();
}