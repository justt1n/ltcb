#include <stdio.h>

void write_text(FILE *f, int a, int b)
{
    fprintf(f, "%d %d", a, b);
}

void write_binary(FILE *f, int x)
{
    fwrite(&x, sizeof(int), 1, f);
}

struct Complex
{
    float real, image;
};

void add_and_write(FILE *f, struct Complex a, struct Complex b)
{
    struct Complex z;
    z.real = a.real + b.real;
    z.image = a.image + b.image;
    fwrite(&z, 8, 1, f);
}

int main()
{
}