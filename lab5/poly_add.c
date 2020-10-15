#include <stdio.h>
#include <stdlib.h>

typedef struct _Term {
    int coeff;
    int exp;
    struct _Term* next;
} Term;

Term* poly_add(Term* poly1, Term* poly2) {
    Term *res_head = NULL, *new_term, *ptr, *temp;

    while (poly1 != NULL || poly2 != NULL) {
        new_term = malloc(sizeof *new_term);
        new_term->next = NULL;
        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->exp > poly2->exp) {
                new_term->coeff = poly1->coeff;
                new_term->exp = poly1->exp;
                temp = poly1;
                poly1 = poly1->next;
                free(temp);
            } else if (poly1->exp < poly2->exp) {
                new_term->coeff = poly2->coeff;
                new_term->exp = poly2->exp;
                temp = poly2;
                poly2 = poly2->next;
                free(temp);
            } else {
                new_term->coeff = poly1->coeff + poly2->coeff;
                new_term->exp = poly1->exp;
                temp = poly1;
                poly1 = poly1->next;
                free(temp);
                temp = poly2;
                poly2 = poly2->next;
                free(temp);
            }
        } else if (poly1 == NULL) {
            new_term->coeff = poly2->coeff;
            new_term->exp = poly2->exp;
            temp = poly2;
            poly2 = poly2->next;
            free(poly2);
        } else {
            new_term->coeff = poly1->coeff;
            new_term->exp = poly1->exp;
            temp = poly1;
            poly1 = poly1->next;
            free(poly1);
        }

        if (new_term->coeff == 0) {
            free(new_term);
            continue;
        }

        if (res_head == NULL) {
            res_head = new_term;
            ptr = res_head;
        } else {
            ptr->next = new_term;
            ptr = ptr->next;
        }
    }

    return res_head;
}

void show_poly(Term* poly) {
    printf("%dx^%d", poly->coeff, poly->exp);
    for (Term* ptr = poly->next; ptr != NULL; ptr = ptr->next)
        printf(" + %dx^%d", ptr->coeff, ptr->exp);
    putchar('\n');
}

int main(void) {
    Term *poly1=NULL, *poly2=NULL, *result, *ptr, *new_term;
    int order_poly1, order_poly2;

    printf("Enter order of polynomial 1: ");
    scanf("%d", &order_poly1);

    for (int i = order_poly1; i >= 0; i--) {
        new_term = malloc(sizeof *new_term);
        new_term->next = NULL;
        
        printf("Enter coefficient of order %d term: ", i);
        scanf("%d", &(new_term->coeff));
        new_term->exp = i;
        
        if (new_term->coeff == 0) {
            free(new_term);
            continue;
        }
        
        if (poly1 == NULL) {
            poly1 = new_term;
            ptr = poly1;
        } else {
            ptr->next = new_term;
            ptr = ptr->next;
        }
    }

    putchar('\n');

    printf("Enter order of polynomial 2: ");
    scanf("%d", &order_poly2);

    for (int i = order_poly2; i >= 0; i--) {
        new_term = malloc(sizeof *new_term);
        new_term->next = NULL;
        
        printf("Enter coefficient of order %d term: ", i);
        scanf("%d", &(new_term->coeff));
        new_term->exp = i;
        
        if (new_term->coeff == 0) {
            free(new_term);
            continue;
        }
        
        if (poly2 == NULL) {
            poly2 = new_term;
            ptr = poly2;
        } else {
            ptr->next = new_term;
            ptr = ptr->next;
        }
    }

    result = poly_add(poly1, poly2);

    show_poly(result);

    return 0;
}
