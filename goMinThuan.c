#include <stdio.h>

#define M 5
#define N 5
#define MINE -1
/*Mảng B lưu bảng đồ mìn*/
int B[M][N];
/*Mảng T lưu trạng thái các ô*/
int T[M][N];

void init()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[i][j] = 0;
            T[i][j] = 0;
        }
    }
    B[1][2] = MINE;
    B[3][1] = MINE;
}

int valid(int i, int j)
{
    if (i - 1 >= 0 && j - 1 >= 0)
        return 1;
    return 0;
}

void count_mines()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int count = 0;
            if (valid(i - 1, j - 1) && B[i - 1][j - 1] == MINE)
                count++;
            if (valid(i - 1, j) && B[i - 1][j] == MINE)
                count++;
            if (valid(i - 1, j + 1) && B[i - 1][j + 1] == MINE)
                count++;
            if (valid(i, j - 1) && B[i][j - 1] == MINE)
                count++;
            if (valid(i, j + 1) && B[i][j + 1] == MINE)
                count++;
            if (valid(i + 1, j - 1) && B[i + 1][j - 1] == MINE)
                count++;
            if (valid(i + 1, j) && B[i + 1][j] == MINE)
                count++;
            if (valid(i + 1, j + 1) && B[i + 1][j + 1] == MINE)
                count++;
            if (B[i][j] != MINE)
                B[i][j] = count;
        }
    }
}

void printMap1()
{
    printf(" ");
    for (int i = 0; i < M; i++)
    {
        printf("%2d", i);
    }
    printf("\n");
    for (int i = 0; i < M; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < N; j++)
        {
            if (B[i][j] == MINE)
            {
                printf("x ");
            }
            else if (B[i][j] == 0)
            {
                printf(". ");
            }
            else
            {
                printf("%d ", B[i][j]);
            }
        }
        printf("\n");
    }
}

void printMap2()
{
    printf(" ");
    for (int i = 0; i < M; i++)
        printf("%2d", i);
    printf("\n");
    for (int i = 0; i < M; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < N; j++)
        {
            if (T[i][j] == 0)
                printf("# ");
            else
            {
                if (B[i][j] == MINE)
                    printf("x ");
                else if (B[i][j] == 0)
                    printf(". ");
                else
                    printf("%d ", B[i][j]);
            }
        }
        printf("\n");
    }
}

int count_remain()
{
    int count = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (T[i][j] == 0)
                count++;
    return count;
}

void open_cell_2(int r, int c)
{
    T[r][c] = 1;
    if (B[r][c] == 0)
    {
        if (valid(r - 1, c - 1))
            T[r - 1][c - 1] = 1;
        if (valid(r - 1, c))
            T[r - 1][c] = 0;
        if (valid(r - 1, c + 1))
            T[r - 1][c + 1] = 1;

        if (valid(r, c - 1))
            T[r][c - 1] = 1;
        if (valid(r, c + 1))
            T[r][c + 1] = 1;

        if (valid(r + 1, c - 1))
            T[r + 1][c - 1] = 1;
        if (valid(r + 1, c))
            T[r + 1][c] = 1;
        if (valid(r + 1, c + 1))
            T[r + 1][c + 1] = 1;
    }
}

void open_cell_3(int r, int c)
{
    if (T[r][c] == 1)
        return;
    if (r >= 0 && r < M && c >= 0 && c < N && B[r][c] != MINE)
    {
        T[r][c] = 1;
        if (B[r][c] == 0)
        {
            open_cell_3(r - 1, c - 1);
            open_cell_3(r - 1, c);
            open_cell_3(r - 1, c + 1);
            open_cell_3(r, c - 1);
            open_cell_3(r, c + 1);
            open_cell_3(r + 1, c - 1);
            open_cell_3(r + 1, c);
            open_cell_3(r + 1, c + 1);
        }
    }
}