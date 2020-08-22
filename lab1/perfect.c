#include <stdio.h>

int sum_of_factors(int);

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == sum_of_factors(n))
        printf("Perfect Number\n");
    else
        printf("Not Perfect Number\n");

    return 0;
}

int sum_of_factors(int n) {
    int s=1;

    for (int i=2; i<n; i++)
        if (n % i == 0)
            s += i;

    return s;
}
