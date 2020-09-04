#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "doubly_linked_list.h"

int main(void) {
    Node* head = NULL;
    int data, elem, index, key;
    char ch;

    do {
        printf("Enter data: ");
        scanf("%d", &data);
        getchar();
        append(&head, data);
        printf("Add more data? (Y/n): ");
        ch = tolower(getchar());
        getchar();
    } while (ch == 'y');

    while (1) {
        printf("\nWHAT DO YOU WANNA DO WITH THIS LIST?\n");
        printf("a) Traverse the list forward\n");
        printf("b) Traverse the list backward\n");
        printf("c) Check if list is empty\n");
        printf("d) Insert a node at certain position (at begining/end/any position)\n");
        printf("e) Delete a node at certain position (at begining/end/any position)\n");
        printf("f) Delete a node for the given key\n");
        printf("g) Count the total number of nodes\n");
        printf("h) Search for an element in the linked list\n");
        printf("i) Quit application\n");

        printf("\nYour choice: ");
        ch = tolower(getchar());
        getchar();
        switch (ch) {
            case 'a':
                print_traversal(head);
                break;

            case 'b':
                print_reverse_traversal(head);
                break;

            case 'c':
                if (is_empty(head))
                    printf("List is empty!\n");
                else
                    printf("List is not empty!\n");
                break;

            case 'd':
                printf("Enter index where you want to add the node: ");
                scanf("%d", &index);
                printf("Enter data: ");
                scanf("%d", &data);
                getchar();
                insert_at(&head, index, data);
                break;

            case 'e':
                printf("Enter index of node to be deleted: ");
                scanf("%d", &index);
                getchar();
                delete_at(&head, index);
                break;

            case 'f':
                printf("Enter key to delete: ");
                scanf("%d", &key);
                getchar();
                delete_key(&head, key);
                break;

            case 'g':
                printf("Count : %d\n", count_nodes(head));
                break;

            case 'h':
                printf("Enter element to be searched: ");
                scanf("%d", &elem);
                getchar();
                if ((index = search(head, elem)) != -1)
                    printf("Element found at index %d\n", index);
                else
                    printf("Search element was not found!\n");
                break;

            default:
                exit(0);
        }
    }

    return 0;
}
