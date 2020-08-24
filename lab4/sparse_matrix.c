// sparse_matrix.c

#include <stdio.h>
#include <stdlib.h>
#include "sparse_matrix.h"

int non_zeroes(int** matrix, int m, int n) {
    int size = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] != 0) size++;

    return size;
}

int is_sparse(int** triplet) {
    // if # of non-zeroes is < half of total # of elements in the matrix, then
    //     it is a sparse matrix
    if (triplet[0][2] < triplet[0][0] * triplet[0][1] / 2)
        return 1;

    return 0;
}

void matrix_to_triplet(int** matrix, int** triplet_form, int m, int n) {
    int k = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] != 0) {
                triplet_form[k] = malloc(3 * sizeof **triplet_form);
                triplet_form[k][0] = i;
                triplet_form[k][1] = j;
                triplet_form[k][2] = matrix[i][j];
                k++;
            }
}

int** input_triplet_form(int m, int n) {
    int** matrix = malloc(m * sizeof *matrix);

    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof **matrix);
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    }

    int size = non_zeroes(matrix, m, n);
    int** triplet_form = malloc((size + 1) * sizeof *triplet_form);
    triplet_form[0] = malloc(3 * sizeof **triplet_form);
    triplet_form[0][0] = m;
    triplet_form[0][1] = n;
    triplet_form[0][2] = size;
    matrix_to_triplet(matrix, triplet_form + 1, m, n);  // pass with 1 offset for the header

    free(matrix);

    return triplet_form;
}

int** transpose_triplet(int** triplet_form) {
    int** transposed_triplet = malloc((triplet_form[0][2] + 1) * sizeof *transposed_triplet);

    for (int i = 0; i < triplet_form[0][2] + 1; i++) {
        transposed_triplet[i] = malloc(3 * sizeof **transposed_triplet);
        transposed_triplet[i][0] = triplet_form[i][1];
        transposed_triplet[i][1] = triplet_form[i][0];
        transposed_triplet[i][2] = triplet_form[i][2];
    }

    return transposed_triplet;
}

int** add_triplets(int** triplet1, int** triplet2) {
    int flag, size_cmp = triplet1[0][2];

    int total_size = triplet1[0][2] + triplet2[0][2] + 1;
    int** triplet_res = malloc(total_size * sizeof *triplet_res);

    // copy triplet1 to triplet_res
    for (int i = 0; i < triplet1[0][2] + 1; i++) {
        triplet_res[i] = malloc(3 * sizeof **triplet_res);
        for (int j = 0; j < 3; j++)
            triplet_res[i][j] = triplet1[i][j];
    }

    for (int j = 1; j < triplet2[0][2] + 1; j++) {
        flag = 0;
        for (int i = 1; i < size_cmp + 1; i++)
            if (triplet_res[i][0] == triplet2[j][0] && triplet_res[i][1] == triplet2[j][1]) {
                triplet_res[i][2] += triplet2[j][2];
                flag = 1;
                break;
            }

        if (flag) continue;

        int index = ++triplet_res[0][2];
        triplet_res[index] = malloc(3 * sizeof **triplet_res);
        for (int k = 0; k < 3; k++)
            triplet_res[index][k] = triplet2[j][k];
    }

    return triplet_res;
}

int** multiply_triplets(int** triplet1, int** triplet2) {
    int flag;
    int** temp_triplet = malloc((triplet1[0][0]*triplet2[0][1] + 1) * sizeof *temp_triplet);

    temp_triplet[0] = malloc(3 * sizeof **temp_triplet);
    temp_triplet[0][0] = triplet1[0][0];
    temp_triplet[0][1] = triplet2[0][1];
    temp_triplet[0][2] = 0;

    for (int i = 1; i < triplet1[0][2] + 1; i++)
        for (int j = 1; j < triplet2[0][2] + 1; j++)
            if (triplet1[i][1] == triplet2[j][0]) {
                flag = 0;
                for (int k = 1; k < temp_triplet[0][2] + 1; k++)
                    if (temp_triplet[k][0] == triplet1[i][0] && temp_triplet[k][1] == triplet2[j][1]) {
                        temp_triplet[k][2] += triplet1[i][2] * triplet2[j][2];
                        flag = 1;
                        break;
                    }

                if (flag) continue;

                int index = ++temp_triplet[0][2];
                temp_triplet[index] = malloc(3 * sizeof **temp_triplet);
                temp_triplet[index][0] = triplet1[i][0];
                temp_triplet[index][1] = triplet2[j][1];
                temp_triplet[index][2] = triplet1[i][2] * triplet2[j][2];
            }

    // make a fresh triplet and copy over only the non-zero entries
    int** product_triplet = malloc((temp_triplet[0][2] + 1) * sizeof *product_triplet);

    product_triplet[0] = malloc(3 * sizeof **product_triplet);
    product_triplet[0][0] = temp_triplet[0][0];
    product_triplet[0][1] = temp_triplet[0][1];
    product_triplet[0][2] = 0;

    for (int i = 1; i < temp_triplet[0][2] + 1; i++)
        if (temp_triplet[i][2] != 0) {
            int index = ++product_triplet[0][2];
            product_triplet[index] = malloc(3 * sizeof **product_triplet);
            for (int j = 0; j < 3; j++)
                product_triplet[index][j] = temp_triplet[i][j];
        }

    free(temp_triplet);

    return product_triplet;
}

void print_triplet_form(int** triplet_form) {
    int flag;

    for (int i = 0; i < triplet_form[0][0]; i++) {
        for (int j = 0; j < triplet_form[0][1]; j++) {
            flag = 0;
            for (int k = 1; k < triplet_form[0][2] + 1; k++)
                if (triplet_form[k][0] == i && triplet_form[k][1] == j) {
                    printf("%d ", triplet_form[k][2]);
                    flag = 1;
                    break;
                }

            if (flag) continue;

            printf("0 ");
        }

        putchar('\n');
    }
}
