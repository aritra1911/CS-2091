#include <stdlib.h>
#include "deque.h"

void enqueue_front(int x, Node** front, Node** rear) {
    Node* new_node = malloc(sizeof *new_node);

    new_node->data = x;
    new_node->next = NULL;

    if (!(*front)) {
        *front = new_node;
        *rear = new_node;
        return;
    }

    new_node->next = *front;
    *front = new_node;
}

void enqueue_rear(int x, Node** front, Node** rear) {
    Node* new_node = malloc(sizeof *new_node);

    new_node->data = x;
    new_node->next = NULL;

    if (!(*front)) {
        *front = new_node;
        *rear = new_node;
        return;
    }

    (*rear)->next = new_node;
    *rear = new_node;
}

int dequeue_rear(Node** front, Node** rear) {
    if (!(*front)) return -999;

    int temp;

    if (*front == *rear) {
        temp = (*front)->data;
        free(*front);
        *front = NULL;
        *rear = NULL;
        return temp;
    }

    temp = (*rear)->data;

    Node* ptr;
    for (ptr = *front; ptr->next != *rear; ptr = ptr->next);

    ptr->next = NULL;
    free(*rear);
    *rear = ptr;
    return temp;
}

int dequeue_front(Node** front, Node** rear) {
    if (!(*front)) return -999;

    int temp;

    if (*front == *rear) {
        temp = (*front)->data;
        free(*front);
        *front = NULL;
        *rear = NULL;
        return temp;
    }

    temp = (*front)->data;
    Node* ptr = *front;
    *front = (*front)->next;
    free(ptr);
    return temp;
}
