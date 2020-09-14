#include <stdio.h>
#include "stack.h"

#define IS_OPENING_BRACKET(c) (c == '(' || c == '{' || c == '[')
#define IS_CLOSING_BRACKET(c) (c == ')' || c == '}' || c == ']')

typedef enum {
    PAREN=1,  // ()
    BRACE,  // {}
    BRACK,  // []
} bracket;

bracket which_bracket(char);

int main(void) {
    Node* top = NULL;
    int c;

    while ((c = getchar()) != EOF) {
        if (IS_OPENING_BRACKET(c))
            push(&top, which_bracket(c));
        else if (IS_CLOSING_BRACKET(c) && pop(&top) != which_bracket(c)) {
            // If the brackets aren't closed in order, then exit.
            printf("NO\n");
            clear(top);
            return 1;
        }
    }

    if (pop(&top)) {
        // If there are still open brackets in the stack, it is unbalanced!
        printf("NO\n");
        clear(top);
        return 1;
    }

    printf("YES\n");

    return 0;
}

bracket which_bracket(char c) {
    switch (c) {
        case '(':
        case ')': return PAREN;
        case '{':
        case '}': return BRACE;
        case '[':
        case ']': return BRACK;
        default: return -1;
    }
}
