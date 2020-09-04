typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

void append(Node**, int);
void reverse(Node**);
void print_traversal(Node*);
