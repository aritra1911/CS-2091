#include <stdio.h>
#include <stdlib.h>
#include "sparse_matrix.h"

int main(void) {
    int **triplet_form;
    int m, n;

    printf("Enter order of matrix:\n");
    scanf("%d %d", &m, &n);

    printf("\nEnter elements of matrix:\n");
    triplet_form = input_triplet_form(m, n);

    if (is_sparse(triplet_form))
        printf("\nGiven matrix is a sparse matrix.\n");
    else
        printf("\nGiven matrix is NOT a sparse matrix.\n");

    free(triplet_form);

    return 0;
}
