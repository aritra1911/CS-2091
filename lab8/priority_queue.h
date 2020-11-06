typedef struct _Node {
    int data;
    int priority;
    struct _Node* next;
} Node;

void enqueue(int, int, Node**, Node**);
int dequeue(Node**, Node**);
