#include <stdio.h>
#include <stdlib.h>
#include "sparse_matrix.h"

int main(void) {
    int **triplet_form1, **triplet_form2, **triplet_result;
    int m, n;

    printf("Enter order of matrices:\n");
    scanf("%d %d", &m, &n);

    printf("\nEnter elements of matrix 1:\n");
    triplet_form1 = input_triplet_form(m, n);

    printf("\nEnter elements of matrix 2:\n");
    triplet_form2 = input_triplet_form(m, n);

    triplet_result = add_triplets(triplet_form1, triplet_form2);

    printf("\nResult of matrix addition :\n");
    print_triplet_form(triplet_result);

    free(triplet_form1);
    free(triplet_form2);
    free(triplet_result);

    return 0;
}
