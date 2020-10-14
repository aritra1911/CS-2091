#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

#define is_opening_bracket(c) (c == ')')
#define is_closing_bracket(c) (c == '(')

int is_operator(int);

int main() {
    Node *top = NULL, *prefix_top = NULL;
    char infix[256];
    int c;

    printf("Enter your infix expression: ");
    scanf("%[^\n]", infix);


    for (int i = strlen(infix) - 1; i >= 0; i--) {
        if (isspace(infix[i])) continue;

        if (is_opening_bracket(infix[i])) {

            push(&top, infix[i]);

        } else if (is_closing_bracket(infix[i])) {

            c = pop(&top);
            while (!is_opening_bracket(c)) {
                push(&prefix_top, c);
                c = pop(&top);
            }

        } else if (c = is_operator(infix[i])) {

            while (is_operator(peek(top)) > c)
                push(&prefix_top, pop(&top));

            push(&top, infix[i]);

        } else
            push(&prefix_top, infix[i]);
    }

    while (c = pop(&prefix_top))
        putchar(c);

    putchar('\n');
}

int is_operator(int c) {
    switch (c) {
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}
