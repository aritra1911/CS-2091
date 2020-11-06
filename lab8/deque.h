typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

void enqueue_front(int, Node**, Node**);
void enqueue_rear(int, Node**, Node**);
int dequeue_rear(Node**, Node**);
int dequeue_front(Node**, Node**);
