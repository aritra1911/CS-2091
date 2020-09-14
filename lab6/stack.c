#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(Node** top, int new_data) {
    Node* new_node = malloc(sizeof *new_node);

    if (new_node == NULL) {
        printf("Overflow!\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = *top;
    *top = new_node;
}

int pop(Node** top) {
    if (is_empty(*top))
        return 0;

    Node* next = (*top)->next;
    int data = (*top)->data;
    free(*top);
    *top = next;
    return data;
}

int peek(Node* top) {
    return top->data;
}

int is_empty(Node* top) {
    return top == NULL;
}

void clear(Node* top) {
    Node* node = top;
    while (node != NULL) pop(&node);
}

void display(Node* top) {
    Node* node = top;

    while (!is_empty(node)) {
        printf("%d\n", peek(node));
        node = node->next;
    }
}
