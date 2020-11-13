#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);

int main(void) {
    int m, n;

    printf("Enter no. of rows and columns of matrix\n");
    scanf("%d %d", &m, &n);

    int** mat = (int**) malloc(m * sizeof(int*));
    for (int i=0; i<m; i++)
        mat[i] = (int*) malloc(n * sizeof(int));

    printf("\nEnter your matrix:\n");
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &mat[i][j]);

    // Swap column entries for each row
    for (int j=0; j<n/2; j++)
        for (int i=0; i<m; i++)
            swap(&mat[i][j], &mat[i][n-j-1]);

    printf("\nResultant Matrix:\n");
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
