#include <stdio.h>
#include <ctype.h>
#include "linked_list.h"

int main(void) {
    Node* head = NULL;
    int data;
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

    reverse(&head);

    printf("\nReversed list:\n");
    print_traversal(head);

    return 0;
}
