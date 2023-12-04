#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *head;

// Tạo node mới
Node *makeNode(int x) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}

// In ra danh sách liên kết
void printlist(Node *head) {
    Node *q = head;
    while (q != NULL) {
        printf("%d ", q->value);
        q = q->next;
    }
}

// Chèn vào cuối 1 node
Node *insertlast(Node *head, int x) {
    Node *newNode = makeNode(x);
    if (head == NULL) return newNode;
    Node *q = head;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = newNode;
    return head;
}

// Chèn vào đầu 1 node
Node *insertfirst(Node *head, int x) {
    Node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
    return head;
}

// Chèn vào sau 1 node
Node *insertAfter(Node *head, Node *p, int x) {
    Node *newNode = makeNode(x);
    newNode->next = p->next;
    p->next = newNode;
    return head;
}

// Tìm phần tử ở trước
Node *prev(Node *head, Node *p) {
    Node *q = head;
    while (q != NULL && q->next != p) {
        q = q->next;
    }
    return q;
}

// Chèn vào trước 1 node
Node *insertBefore(Node *head, Node *p, int x) {
    Node *pp = prev(head, p);
    Node *newNode = makeNode(x);
    if (pp == NULL && p != NULL) return head;
    if (pp == NULL) {
        if (head == NULL) return newNode;
        newNode->next = head;
        return newNode;
    }
    newNode->next = p;
    pp->next = newNode;
    return head;
}

// Xóa tất cả các node có giá trị v
Node *removeall(Node *head, int v) {
    if (head == NULL) return NULL;
    Node *q = head;

    // Cần lưu ý trường hợp node đầu tiên
    while (head != NULL && head->value == v) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }

    while (q != NULL && q->next != NULL) {
        if (q->next->value == v) {
            Node *pq = prev(head, q->next);
            Node *q2 = q->next;
            pq->next = q2->next;
            free(q2);
        } else {
            q = q->next;
        }
    }
    return head;
}

// Xóa tất cả các node có giá trị lớn hơn v
Node *removeBigger(Node *head, int v) {
    if (head == NULL) return NULL;
    Node *q = head;

    // Cần lưu ý trường hợp node đầu tiên
    while (head != NULL && head->value > v) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }

    while (q != NULL && q->next != NULL) {
        if (q->next->value > v) {
            Node *pq = prev(head, q->next);
            Node *q2 = q->next;
            pq->next = q2->next;
            free(q2);
        } else {
            q = q->next;
        }
    }
    return head;
}

Node * reverseNode(Node * head){
	Node * p = head;
	Node * pp = NULL;
	Node * np = NULL;
	while(p != NULL){
		np = p -> next;
		p -> next = pp;
		pp = p;
		p = np;
	}
	return pp;
}

int main() {
    int n;
    scanf("%d", &n);
    int x;
    scanf("%d", &x);
    head = makeNode(x);
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        head = insertlast(head, x);
    }
    int v; scanf("%d", &v);
    head = removeBigger(head, v);
    head = reverseNode(head);
    printlist(head);
//Thu hồi danh sách
    while(head !=NULL){
	    Node * tmp = head;
	    head = head -> next;
	    free(tmp);
    }
}
