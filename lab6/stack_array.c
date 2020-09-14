#include <stdio.h>
#include <ctype.h>

#define STACK_SIZE 5

int top = -1;
int stack[STACK_SIZE];

void push(int new_data) {
    if (top == STACK_SIZE - 1) {
        printf("Overflow!\n");
        return;
    }
    stack[++top] = new_data;
}

int pop(void) {
    if (top == -1) {
        printf("Underflow!\n");
        return -1;
    }
    return stack[top--];
}

int is_empty(void) {
    return top == -1;
}

int display(void) {
    for (int i = top; i > -1; i--)
        printf("%d\n", stack[i]);
}

int main(void) {
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
                if (is_empty())
                    printf("Stack is empty!\n");
                else
                    printf("Stack isn't empty!\n");
                break;

            case 'b':
                display();
                break;

            case 'c':
                printf("Enter data to push: ");
                scanf("%d", &data);
                getchar();
                push(data);
                break;

            case 'd':
                if ((data = pop()) != -1)
                    printf("Popped : %d\n", data);
                break;

            default:
                return 0;
        }
    }

    return 0;
}
