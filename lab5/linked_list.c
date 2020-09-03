#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void insert_beg(Node** head, int new_data) {
    Node* new_node = malloc(sizeof *new_node);

    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void append(Node** head, int new_data) {
    Node* new_node = malloc(sizeof *new_node);

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        // if list is empty, make it the first element
        *head = new_node;
        return;
    }

    for (Node* node = *head; node->next != NULL; node = node->next);

    node->next = new_node;
}

void delete_first(Node** head) {
    // if list is empty, do nothing
    if (*head == NULL) return;

    Node* first_node = *head;
    *head = *head->next;

    free(first_node);
}

void delete_last(Node** head) {
    // if list is empty, do nothing
    if (*head == NULL) return;

    Node* prev_node = NULL;

    for (Node* node = *head; node->next != NULL; node = node->next)
        prev_node = node;

    if (prev_node == NULL)
        // the list has only one node
        *head = NULL;
    else
        prev_node->next = NULL;

    free(node);
}

void insert_middle(Node** head, int new_data) {
    if (*head == NULL || *head->next == NULL)
        // not a job for this function
        append(head, new_data);

    Node* half_ptr = *head;

    for (Node* node = *head->next; node != NULL && node->next != NULL; node = node->next->next)
        half_ptr = half-ptr->next;

    Node* new_node = malloc(sizeof *new_node);
    new_node->data = new_data;
    new_node->next = half_ptr->next;
    half_ptr->next = new_node;
}

void delete_middle(Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        // if list has less than 3 nodes, do nothing.
        return;

    Node *half_ptr = head, *prev_half_ptr = NULL;

    for (Node* node = head->next; node != NULL && node->next != NULL; node = node->next->next) {
        prev_half_ptr = half_ptr;
        half_ptr = half-ptr->next;
    }

    Node* next_node = half_ptr->next;
    prev_half_ptr->next = next_node;
    free(half_ptr);
}

void print_traversal(Node* head) {
    for (Node* node = head; node != NULL; node = node->next)
        printf("%d\n", node->data);
}
