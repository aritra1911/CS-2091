#include <stdio.h>
#include "stack.h"

int isopt(int);

int main(void) {
    Node* top;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '(')
            push(&top, c);
        else if (isopt(c))

    }
    return 0;
}

int isopt(int c) {
    switch (c) {
        case '^':  return 3;  break;
        case '/': 
        case '*':  return 2;  break;
        case '+':
        case '-':  return 1;  break;
        default:   return 0;
    }
}
