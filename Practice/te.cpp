#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct
{
    char ten[MAX_LENGTH];
    char dh;
    float diem;
} ThiSinh;

void nhap(ThiSinh *a, FILE *in)
{
    fgets(a->ten, MAX_LENGTH, in);
    fscanf(in, "%f %c", &a->diem, &a->dh);
    fgetc(in); // Consume newline character
}

void xuat(ThiSinh *a, FILE *out)
{
    fprintf(out, "%s %.2f %c\n", a->ten, a->diem, a->dh);
}

int cmp(const void *a, const void *b)
{
    const ThiSinh *aa = (const ThiSinh *)a;
    const ThiSinh *bb = (const ThiSinh *)b;
    return (aa->diem < bb->diem) - (aa->diem > bb->diem);
}

void sapxep(ThiSinh a[], int n)
{
    qsort(a, n, sizeof(ThiSinh), cmp);
}

double SumPoint(ThiSinh a[], int n, char c)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].dh == c)
            sum += a[i].diem;
    }
    return sum;
}

int main()
{
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    ThiSinh ds[50];
    int n;
    fscanf(in, "%d", &n);
    fgetc(in); // Consume newline character
    for (int i = 0; i < n; i++)
        nhap(&ds[i], in);
    sapxep(ds, n);

    double a, b, c, res;
    a = SumPoint(ds, n, 'A');
    b = SumPoint(ds, n, 'B');
    c = SumPoint(ds, n, 'C');
    res = (a < b) ? (a < c ? a : c) : (b < c ? b : c);
    fprintf(out, "Diem A: %.2f\n", a);
    fprintf(out, "Diem B: %.2f\n", b);
    fprintf(out, "Diem C: %.2f\n", c);
    char x;
    if (res == a)
        x = 'A';
    else if (res == b)
        x = 'B';
    else
        x = 'C';
    fprintf(out, "Truong %c co diem thap nhat\n", x);
    fprintf(out, "Top 3: \n");
    for (int i = 0; i < 3; i++) // Change to print top 3 students
        xuat(&ds[i], out);

    fclose(in);
    fclose(out);

    return 0;
}
