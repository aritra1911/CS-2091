#include <stdio.h>
#include <stdlib.h>

void segregate(int*, size_t);
void swap(int*, int*);

int main() {
    int* arr;
    size_t n;

    printf("Enter no. of elements: ");
    scanf("%lu", &n);

    arr = malloc(n * sizeof *arr);

    // poppulate
    for (size_t i=0; i<n; i++)
        scanf("%d", &arr[i]);

    segregate(arr, n);

    printf("\nSegregated array :\n");
    for (size_t i=0; i<n; i++)
        printf("%d\n", arr[i]);

    free(arr);

    return 0;
}

void segregate(int a[] , size_t n) {
    size_t left=0, right=n-1;

    while(left < right) {
        while((a[left] & 1) && left<right)
            left++;

        while(!(a[right] & 1) && left<right)
            right--;

        if(left < right)
            swap(&a[left], &a[right]);
    }
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}
