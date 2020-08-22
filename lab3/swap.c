#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);

int main() {
    int** mat;
    int m, n;

    printf("Enter dimensions of matrix:\n");
    scanf("%d %d", &m, &n);

    mat = malloc(m * sizeof *mat);

    for (int i=0; i<m; i++)
        mat[i] = malloc(n * sizeof **mat);

    printf("Enter matrix elements:\n");
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &mat[i][j]);

    for (int i=0; i<m; i++)
        for (int j=0; j<n/2; j++)
            swap(&mat[i][j], &mat[i][n-j-1]);

    printf("\nFinal matrix:\n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            printf("%d ", mat[i][j]);
        putchar('\n');
    }

    return 0;
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}
