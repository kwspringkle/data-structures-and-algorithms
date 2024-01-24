#include <stdio.h>
#include <stdlib.h>

typedef struct dNode {
    int value;
    struct dNode* prev;
    struct dNode* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

// Hàm tạo node mới
Node* makeNode(int x) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Chèn 1 node vào cuối danh sách
void insertlast(int x) {
    Node* newNode = makeNode(x);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Chèn 1 Node vào đầu danh sách
void insertfirst(int x) {
    Node* newNode = makeNode(x);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Hàm hiển thị toàn bộ danh sách từ head đến tail
void printListLeft2Right() {
    for (Node* current = head; current != NULL; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}

// Hàm hiển thị toàn bộ danh sách từ tail đến head
void printListRight2Left() {
    for (Node* current = tail; current != NULL; current = current->prev)
        printf("%d ", current->value);
    printf("\n");
}

// Hàm tìm node có giá trị v trong danh sách
Node* findNode(int v) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == v) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Hàm chèn 1 node có giá trị x vào trước node có giá trị v
void addBefore(int u, int v) {
    Node* newNode = makeNode(u);
    Node* foundNode = findNode(v);

    if (foundNode == NULL) {
        printf("Node có giá trị %d không tồn tại trong danh sách.\n", v);
        free(newNode);
        return;
    }

    newNode->prev = foundNode->prev;
    newNode->next = foundNode;
    if (foundNode->prev != NULL) {
        foundNode->prev->next = newNode;
    } else {
        head = newNode;
    }
    foundNode->prev = newNode;
}

Node* findNode_by_index(int index) {
    int count = -1;
    Node* q = head;
    while (q != NULL) {
        count++;
        if (count == index) {
            return q;
        }
        q = q->next;
    }
    return NULL;
}

Node* prev(Node* p) {
    Node* q = head;
    while (q != NULL) {
        if (q->next == p) {
            return q;
        }
        q = q->next;
    }
    return NULL;
}

void addAt(int index, int v, int size) {
    Node* newnode = makeNode(v);
    if (index == 0) {
        insertfirst(v);
    } else if (index == size) {
        insertlast(v);
        size++;
    } else {
        Node* curr = findNode_by_index(index);
        Node* prevcurr = prev(curr);
        newnode->next = curr;
        newnode->prev = prevcurr;
        curr->prev = newnode;
        prevcurr->next = newnode;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertlast(x);
    }
    int index;
    int v;
    scanf("%d %d", &index, &v);
    addAt(index, v, n);
    printListLeft2Right();
    return 0;
}
