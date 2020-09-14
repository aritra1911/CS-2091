typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

void push(Node**, int);
int pop(Node**);
int peek(Node*);
int is_empty(Node*);
void clear(Node*);
void display(Node*);
