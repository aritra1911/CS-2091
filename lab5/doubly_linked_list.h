typedef struct _Node {
    struct _Node* prev;
    int data;
    struct _Node* next;
} Node;

void append(Node**, int);
void print_traversal(Node*);
void print_reverse_traversal(Node*);
int is_empty(Node*);
void delete_at(Node**, int);
void delete_key(Node**, int);
void insert_at(Node**, int, int);
int count_nodes(Node*);
int search(Node*, int);
void remove_duplicates(Node*);
