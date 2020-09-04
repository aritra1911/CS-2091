#include <stdio.h>
#include <ctype.h>
#include "doubly_linked_list.h"

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

    remove_duplicates(head);

    printf("\nResultant list:\n");
    print_traversal(head);

    return 0;
}
