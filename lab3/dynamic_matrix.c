#include <stdio.h>
#include <stdlib.h>

size_t non_zeros(int*, size_t);
int sum_above_diag(int*, size_t);
void display_below_minor(int*, size_t);
long product_diags(int*, size_t);

int main() {
    int* a;
    size_t n;

    printf("Enter dimension matrix: ");
    scanf("%lu", &n); getchar();

    a = malloc(n * n * sizeof *a);

    printf("Enter the elements of the matrix:\n");
    for (size_t i=0; i<n; i++)
        for (size_t j=0; j<n; j++) {
            scanf("%d", &a[i*n + j]);
            getchar();
        }

    printf("Number of non-zero elements : %lu\n", non_zeros(a, n));
    printf("Sum of the elements above the leading diagonal : %d\n", sum_above_diag(a, n));
    printf("Elements below the minor diagonal :\n");
    display_below_minor(a, n);
    printf("Product of elements along diagonals : %ld\n", product_diags(a, n));

    return 0;
}

size_t non_zeros(int a[], size_t n) {
    size_t nz = 0;
    for (size_t i=0; i<n; i++)
        for (size_t j=0; j<n; j++)
            if (a[i*n + j] != 0)
                nz++;

    return nz;
}

int sum_above_diag(int a[], size_t n) {
    int sum_leading = 0;
    for (size_t i=0; i<n; i++)
        for (size_t j=0; j<n; j++)
            if (j > i)
                sum_leading += a[i*n + j];

    return sum_leading;
}

void display_below_minor(int a[], size_t n) {
    for (size_t i=0; i<n; i++) {
        for (size_t j=0; j<n; j++) {
            if (i + j >= n)
                printf("%d", a[i*n + j]);
            else
                putchar(' ');
            putchar(' ');
        }
        putchar('\n');
    }
}

long product_diags(int a[], size_t n) {
    long product=1;
    for (size_t i=0; i<n; i++)
        for (size_t j=0; j<n; j++)
            if (i == j || i + j == n - 1)
                product *= a[i*n + j];

    return product;
}
