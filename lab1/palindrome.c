#include <stdio.h>

int reverse(int);

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == reverse(n))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}

int reverse(int n) {
    int r=0;

    while (n > 0) {
        r = r*10 + n%10;
        n /= 10;
    }

    return r;
}
