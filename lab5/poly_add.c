#include <stdio.h>
#include <stdlib.h>

typedef struct _Term {
    int coeff;
    int exp;
    struct _Term* next;
} Term;

Term* poly_add(Term* poly1, Term* poly2) {
    Term *res_head = NULL, *c_term, *temp;

    while (poly1 != NULL || poly2 != NULL) {
        if (res_head == NULL) {
            c_term = malloc(sizeof *c_term);
            c_term->next = NULL;
            res_head = c_term;
        } else {
            c_term->next = malloc(sizeof *c_term->next);
            c_term = c_term->next;
            c_term->next = NULL;
        }

        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->exp > poly2->exp) {
                c_term->coeff = poly1->coeff;
                c_term->exp = poly1->exp;
                temp = poly1;
                poly1 = poly1->next;
                free(temp);
            } else if (poly1->exp < poly2->exp) {
                c_term->coeff = poly2->coeff;
                c_term->exp = poly2->exp;
                temp = poly2;
                poly2 = poly2->next;
                free(temp);
            } else {
                c_term->coeff = poly1->coeff + poly2->coeff;
                c_term->exp = poly1->exp;
                temp = poly1;
                poly1 = poly1->next;
                free(temp);
                temp = poly2;
                poly2 = poly2->next;
                free(temp);
            }
        } else if (poly1 == NULL) {
            c_term->coeff = poly2->coeff;
            c_term->exp = poly2->exp;
            temp = poly2;
            poly2 = poly2->next;
            free(poly2);
        } else {
            c_term->coeff = poly1->coeff;
            c_term->exp = poly1->exp;
            temp = poly1;
            poly2 = poly1->next;
            free(poly1);
        }
    }

    return res_head;
}

int main(void) {
    Term *poly1=NULL, *poly2=NULL, *result, *ptr;
    int order_poly1, order_poly2;

    printf("Enter order of polynomial 1: ");
    scanf("%d", &order_poly1);

    for (int i=0; i<=order_poly1; i++) {
        if (poly1 == NULL) {
            ptr = malloc(sizeof *ptr);
            ptr->next = NULL;
            poly1 = ptr;
        } else {
            ptr->next = malloc(sizeof *ptr->next);
            ptr = ptr->next;
            ptr->next = NULL;
        }
        printf("Enter coefficient of order %d term: ", i);
        scanf("%d", &(ptr->coeff));
        ptr->exp = i;
    }

    putchar('\n');

    printf("Enter order of polynomial 2: ");
    scanf("%d", &order_poly2);

    for (int i=0; i<=order_poly2; i++) {
        if (poly2 == NULL) {
            ptr = malloc(sizeof *ptr);
            ptr->next = NULL;
            poly2 = ptr;
        } else {
            ptr->next = malloc(sizeof *ptr->next);
            ptr = ptr->next;
            ptr->next = NULL;
        }
        printf("Enter coefficient of order %d term: ", i);
        scanf("%d", &(ptr->coeff));
        ptr->exp = i;
    }

    result = poly_add(poly1, poly2);

    printf("%dx^%d", result->coeff, result->exp);
    for (ptr = result->next; ptr != NULL; ptr = ptr->next)
        printf(" + %dx^%d", result->coeff, result->exp);

    return 0;
}
