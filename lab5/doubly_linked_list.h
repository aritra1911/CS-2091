typedef struct _Node {
    struct _Node* prev;
    int data;
    struct _Node* next;
} Node;

void append(Node**, int);
void print_traversal(Node*);
void print_reverse_traversal(Node*);
int is_empty(Node*);
void insert_at(Node**, int);
int count_nodes(Node*);
int search(Node*, int);
