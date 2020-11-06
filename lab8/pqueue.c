#include <stdio.h>
#include "priority_queue.h"

int get_data(void);
int get_priority(void);
void show_queue(Node*, Node*);

int main(void) {
    Node *front=NULL, *rear=NULL;
    int ch, x;

    while (1) {
        printf("1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Show queue\n");
        printf("4) Exit\n");

        printf("\nYour Choice: ");
        ch = getchar();
        getchar();

        switch (ch) {
            case '1':
                enqueue(get_data(), get_priority(), &front, &rear);
                break;

            case '2':
                if ((x = dequeue(&front, &rear)) == -999) {
                    printf("No element to dequeue!\n");
                    break;
                }
                printf("Dequeued: %d\n", x);
                break;

            case '3':
                show_queue(front, rear);
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

int get_priority(void) {
    int d;
    printf("Enter priority: ");
    scanf("%d", &d);
    getchar();
    return d;
}

void show_queue(Node* front, Node* rear) {
    if (!front) {
        printf("No element to show\n");
        return;
    }

    for (Node* ptr=front; ptr!=rear; ptr=ptr->next) {
        printf("%d", ptr->data);
        printf(" -> ");
    }
    printf("%d\n", rear->data);
}
