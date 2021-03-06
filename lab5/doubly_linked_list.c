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
    if (index == 0 || *head == NULL) {
        insert_beg(head, new_data);
        return;
    }

    int flag = 0;
    Node* node = *head;
    for (int i = 0; i < index; i++) {
        if (node->next == NULL) {
            flag = 1;
            break;
        }
        node = node->next;
    }

    if (flag) {
        printf("Warning: Specified index is beyond the scope of the list\n");
        printf("Appending instead\n");
        append(head, new_data);
        return;
    }

    Node* new_node = malloc(sizeof *new_node);
    new_node->data = new_data;

    node->prev->next = new_node;
    new_node->prev = node->prev;
    node->prev = new_node;
    new_node->next = node;
}

void print_traversal(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    for (Node* node = head; node != NULL; node = node->next)
        printf("%d\n", node->data);
}

void print_reverse_traversal(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* ptr;
    for (ptr = head; ptr->next != NULL; ptr = ptr->next);

    for(; ptr != NULL; ptr = ptr->prev)
        printf("%d\n", ptr->data);
}

int is_empty(Node* head) {
    return head == NULL;
}

void delete_at(Node** head, int index) {
    if (*head == NULL) {
        printf("Error: The list is empty!\n");
        return;
    }

    if (index == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    Node* ptr = *head;
    int flag = 0;
    for (int i = 0; i < index; i++) {
        if (ptr->next == NULL) {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (flag) {
        printf("Error: Cannot delete since specified index is beyond the scope of the list\n");
        return;
    }

    ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    free(ptr);
}

void delete_key(Node** head, int key) {
    while ((*head) != NULL && (*head)->data == key) {
        if ((*head)->next != NULL)
            (*head)->next->prev = NULL;
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if (*head == NULL)
        return;

    Node* ptr;
    for (ptr = *head; ptr != NULL; ptr = ptr->next)
        if (ptr->data == key) {
            Node* temp = ptr->prev;
            ptr->prev->next = ptr->next;
            if (ptr->next != NULL)
                ptr->next->prev = ptr->prev;
            free(ptr);
            ptr = temp;
        }
}

int count_nodes(Node* head) {
    int nodes = 0;
    for (Node* ptr = head; ptr != NULL; ptr = ptr->next)
        nodes++;

    return nodes;
}

int search(Node* head, int search_element) {
    int index = 0;
    for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
        if (ptr->data == search_element)
            return index;

        index++;
    }

    return -1;
}

void remove_duplicates(Node* head) {
    if (head == NULL)
        return;

    for (Node* ptr = head; ptr != NULL && ptr->next != NULL; ptr = ptr->next) {
        for (Node* qtr = ptr->next; qtr != NULL; qtr = qtr->next) {
            if (qtr->data == ptr->data) {
                Node* temp = qtr->prev;
                qtr->prev->next = qtr->next;
                if (qtr->next != NULL)
                    qtr->next->prev = qtr->prev;
                free(qtr);
                qtr = temp;
            }
        }
    }
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
