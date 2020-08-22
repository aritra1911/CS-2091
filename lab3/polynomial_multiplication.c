#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int poly1[10], poly2[10], *result;
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

    max_order = order_poly1 + order_poly2;
    result = calloc(max_order + 1, sizeof *result);

    for (int i=0; i<=order_poly1; i++)
        for (int j=0; j<=order_poly2; j++)
            result[i+j] += poly1[i] * poly2[j];

    putchar('\n');

    printf("Result : %dx^%d", result[max_order], max_order);
    for (int i=max_order-1; i>=0; i--)
        printf(" + %dx^%d", result[i], i);

    free(result);

    putchar('\n');

    return 0;
}
