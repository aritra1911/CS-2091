#include <stdio.h>

void swap(int*, int*);

int main(void) {
    int a, b;

    printf("Enter a & b: ");
    scanf("%d %d", &a, &b);

    printf("Value of a & b before swapping : %d, %d\n", a, b);
    swap(&a, &b);
    printf("Value of a & b after swapping : %d, %d\n", a, b);

    return 0;
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}
