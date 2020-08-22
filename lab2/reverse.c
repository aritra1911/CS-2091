#include <stdio.h>

void swap(int*, int*);

int main() {
    int arr[10];

    printf("Enter 10 elements:\n");
    for (int i=0; i<10; i++)
        scanf("%d", &arr[i]);

    for (int i=0; i<5; i++)
        swap(&arr[i], &arr[10-i-1]);

    printf("\nReversed array:\n");
    for (int i=0; i<10; i++)
        printf("%d\n", arr[i]);

    return 0;
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}
