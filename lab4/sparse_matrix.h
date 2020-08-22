// sparse_matrix.h

int   non_zeroes(int**, int, int);
int   is_sparse(int**);
void  matrix_to_triplet(int**, int**, int, int);
int** input_triplet_form(int, int);
int** transpose_triplet(int**);
int** add_triplets(int**, int**);
int** multiply_triplets(int**, int**);
void  print_triplet_form(int**);
