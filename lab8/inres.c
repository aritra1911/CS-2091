#include <stdio.h>
#include "deque.h"

int get_data(void);
void show_deque(Node*, Node*);

int main(void) {
    Node *front=NULL, *rear=NULL;
    int ch, x;

    while (1) {
        printf("1) Enqueue\n");
        printf("2) Dequeue front\n");
        printf("3) Dequeue rear\n");
        printf("4) Show deque\n");
        printf("5) Exit\n");

        printf("\nYour Choice: ");
        ch = getchar();
        getchar();

        switch (ch) {
            case '1':
                enqueue_rear(get_data(), &front, &rear);
                break;

            case '2':
                if ((x = dequeue_front(&front, &rear)) == -999) {
                    printf("No element to dequeue!\n");
                    break;
                }
                printf("Dequeued: %d\n", x);
                break;

            case '3':
                if ((x = dequeue_rear(&front, &rear)) == -999) {
                    printf("No element to dequeue!\n");
                    break;
                }
                printf("Dequeued: %d\n", x);
                break;

            case '4':
                show_deque(front, rear);
                break;

            default:
                return 0;
        }
        printf("\n");
    }
}

int get_data(void) {
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    getchar();
    return d;
}

void show_deque(Node* front, Node* rear) {
    for (Node* ptr=front; ptr!=NULL; ptr=ptr->next) {
        printf("%d", ptr->data);
        if (ptr->next != NULL)
            printf(" -> ");
    }
    printf("\n");
}
