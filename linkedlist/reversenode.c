#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node node;

node* makenode(int x) {
    node* newnode = malloc(sizeof(node));
    newnode->value = x;
    newnode->next = NULL;
    return newnode;
}

node* pushback(node* head, int x) {
    node* newnode = makenode(x);
    if (head == NULL) return newnode;
    node* q = head;
    while (q->next != NULL) { // Fixed condition here
        q = q->next;
    }
    q->next = newnode; // Fixed assignment here
    return head;
}

node* find(node* head, int index) {
    node* q = head;
    int count = 1; // Fixed initialization of count
    while (q != NULL) {
        if (count == index) {
            return q;
        }
        count++;
        q = q->next;
    }
    return NULL;
}

node* reverse(node* head, int left, int right) {
    node* prev = NULL;
    node* current = head;
    int count = 1;
    while (count < left && current != NULL) {
        prev = current;
        current = current->next;
        count++;
    }
    node* start = prev;
    node* tail = current;
    while (count <= right && current != NULL) {
        node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (start != NULL) {
        start->next = prev;
    } else {
        head = prev;
    }
    tail->next = current;
    return head;
}

void printlist(node* head) {
    node* q = head;
    while (q != NULL) {
        printf("%d ", q->value);
        q = q->next;
    }
}

int main() {
    node* head = NULL;
    char k = '\n';
    while (1) {
        int a;
        if (scanf("%d", &a) == EOF) break;
        head = pushback(head, a);
        if (getchar() == k) break;
    }
    int left;
    scanf("%d", &left);
    int right;
    scanf("%d", &right);
    head = reverse(head, left, right);
    printlist(head);
    return 0;
}
