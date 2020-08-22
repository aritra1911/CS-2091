#include <stdio.h>
#include <stdlib.h>

int getNGE(int*, size_t, size_t);

int main(void) {
    int *a;
    size_t n;

    printf("Enter the number of elements in the array: ");
    scanf("%lu", &n); getchar();

    a = malloc(n * sizeof *a);

    printf("Enter the elements of the array:\n");
    for (size_t i=0; i<n; i++) {
        scanf("%d", &a[i]);
        getchar();
    }

    printf("The elements and their NGEs are listed below:\nElement\tNGE\n");

    for (size_t i=0; i<n; i++)
        printf("%d\t%d\n", a[i], getNGE(a, n, i));

    free(a);

    return 0;
}

int getNGE(int a[], size_t n, size_t pos) {
    size_t index_of_max = pos;

    // store the index of the first largest element right of pos
    for (size_t i = pos+1; i < n; i++)
        if (a[i] > a[index_of_max]) {
            index_of_max = i;
            break;
        }

    // if unaltered, it is the largest element.
    if (pos == index_of_max) return -1;

    return a[index_of_max];
}
