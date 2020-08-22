#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr;
    size_t n;

    printf("Enter no. of elements: ");
    scanf("%lu", &n);

    arr = malloc(n * sizeof *arr);

    for (size_t i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int largest = arr[0];  // assume the first element then check
    for (size_t i=1; i<n; i++)
        if (arr[i] > largest)
            largest = arr[i];

    free(arr);

    printf("Largest element : %d\n", largest);

    return 0;
}
