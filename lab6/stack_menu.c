#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int main(void) {
    Node* top = NULL;
    int data;
    char ch;

    while (1) {
        printf("\nWHAT DO YOU WANNA DO WITH THIS STACK?\n");
        printf("a) Check if empty\n");
        printf("b) Display contents\n");
        printf("c) Push\n");
        printf("d) Pop\n");
        printf("e) Exit\n");

        printf("\nYour choice: ");
        ch = tolower(getchar());
        getchar();
        switch (ch) {
            case 'a':
                if (is_empty(top))
                    printf("Stack is empty!\n");
                else
                    printf("Stack isn't empty!\n");
                break;

            case 'b':
                display(top);
                break;

            case 'c':
                printf("Enter data to push: ");
                scanf("%d", &data);
                getchar();
                if (!push(&top, data))
                    printf("Overflow!\n");
                break;

            case 'd':
                if ((data = pop(&top)))
                    printf("Popped : %d\n", data);
                else
                    printf("Underflow!\n");
                break;

            default:
                return 0;
        }
    }

    return 0;
}
