#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

void append(Node** head, int new_data) {
    Node* new_node = malloc(sizeof *new_node);

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    Node* node;
    for (node = *head; node->next != NULL; node = node->next);

    new_node->prev = node;
    node->next = new_node;
}

void insert_beg(Node** head, int new_data) {
    Node* new_node = malloc(sizeof *new_node);

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

void insert_at(Node** head, int index, int new_data) {
    if (index == 0) {
        insert_beg(head, new_data);
        return;
    }

    Node* new_node = malloc(sizeof *new_node);
    Node* node = *head;

    for (int i = 0; i < index; i++)
        node = node->next;

    new_node->data = new_data;

    node->prev->next = new_node;
    new_node->prev = node->prev;
    node->prev = new_node;
    new_node->next = node;
}

void print_traversal(Node* head) {
    for (Node* node = head; node != NULL; node = node->next)
        printf("%d\n", node->data);
}

// 1. Insert at begining in circular doubly linked list
// 2. Insert at the end in circuar doubly linked list

void circular_insert_beg(Node** head, int new_data) {
    Node* new_node = malloc(sizeof *new_node);
    new_node->data = new_data;

    if (*head == NULL) {
        new_node->prev = new_node;
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    (*head)->prev->next = new_node;
    new_node->prev = (*head)->prev;
    (*head)->prev = new_node;
    new_node->next = *head;
    *head = new_node;
}

void circular_insert_end(Node** head, int new_data) {
    Node* new_node = malloc(sizeof *new_node);
    new_node->data = new_data;

    if (*head == NULL) {
        new_node->prev = new_node;
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    (*head)->prev->next = new_node;
    new_node->prev = (*head)->prev;
    (*head)->prev = new_node;
    new_node->next = *head;
}

void circular_print_traversal(Node* head) {
    if (head == NULL)
        return;

    printf("%d\n", head->data);
    for (Node* node = head->next; node != head; node = node->next)
        printf("%d\n", node->data);
}

int main(void) {
    Node* head=NULL;
    for (int i = 0; i < 20; i++)
        append(&head, i);

    insert_at(&head, 20, 421);

    print_traversal(head);

    free(head);

    return 0;
}
