#include <stdio.h>
#include <stdlib.h>
#include "sparse_matrix.h"

int main(void) {
    int **triplet_form, **transposed_triplet_form;
    int m, n;

    printf("Enter order of matrix:\n");
    scanf("%d %d", &m, &n);

    printf("\nEnter elements of matrix:\n");
    triplet_form = input_triplet_form(m, n);

    transposed_triplet_form = transpose_triplet(triplet_form);

    printf("\nTransposed matrix:\n");
    print_triplet_form(transposed_triplet_form);

    free(triplet_form);

    return 0;
}
