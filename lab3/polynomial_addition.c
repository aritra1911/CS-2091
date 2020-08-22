#include <stdio.h>

int main(void) {
    int poly1[10], poly2[10], result[10];
    int order_poly1, order_poly2, max_order;

    printf("Enter order of polynomial 1: ");
    scanf("%d", &order_poly1);

    for (int i=0; i<=order_poly1; i++) {
        printf("Enter coefficient of order %d term: ", i);
        scanf("%d", &poly1[i]);
    }

    putchar('\n');

    printf("Enter order of polynomial 2: ");
    scanf("%d", &order_poly2);

    for (int i=0; i<=order_poly2; i++) {
        printf("Enter coefficient of order %d term: ", i);
        scanf("%d", &poly2[i]);
    }

     max_order = (order_poly1 > order_poly2) ? order_poly1 : order_poly2;

    // copy the bigger polynomial to result and then
    // add the coefficients of smaller polynomial to it
    if (order_poly1 > order_poly2) {
        for (int i=0; i<=order_poly1; i++)
            result[i] = poly1[i];

        for (int i=0; i<=order_poly2; i++)
            result[i] += poly2[i];
    } else {
        for (int i=0; i<=order_poly2; i++)
            result[i] = poly2[i];

        for (int i=0; i<=order_poly1; i++)
            result[i] += poly1[i];
    }

    putchar('\n');

    printf("Result : %dx^%d", result[max_order], max_order);
    for (int i=max_order-1; i>=0; i--)
        printf(" + %dx^%d", result[i], i);

    putchar('\n');

    return 0;
}
