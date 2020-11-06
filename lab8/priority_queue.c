#include <stdlib.h>
#include "priority_queue.h"

void enqueue(int x, int priority, Node** front, Node** rear) {
    Node* new_node = malloc(sizeof *new_node);

    new_node->data = x;
    new_node->priority = priority;
    new_node->next = NULL;

    if (!(*front)) {
        *front = new_node;
        *rear = new_node;
        return;
    }

    if (priority < (*front)->priority) {
        new_node->next = *front;
        *front = new_node;
        return;
    }

    for (Node* ptr=*front; ptr != *rear; ptr=ptr->next)
        if (priority < ptr->next->priority) {
            new_node->next = ptr->next;
            ptr->next = new_node;
            return;
        }

    (*rear)->next = new_node;
    *rear = new_node;
}

int dequeue(Node** front, Node** rear) {
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
