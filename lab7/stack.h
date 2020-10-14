typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

int push(Node**, int);
int pop(Node**);
int peek(Node*);
int is_empty(Node*);
void clear(Node*);
void display(Node*);
