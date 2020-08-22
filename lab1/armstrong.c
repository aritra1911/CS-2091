#include <stdio.h>
#include <math.h>

int digits(int);

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int power = digits(n);
    int m = n, sum = 0;

    while (n > 0) {
        sum += pow(n%10, power);
        n /= 10;
    }

    if (m == sum)
        printf("Armstrong Number\n");
    else
        printf("Not Armstrong Number\n");

    return 0;
}

int digits(int n) {
    int c=0;

    while (n > 0) {
        c++;
        n /= 10;
    }

    return c;
}
