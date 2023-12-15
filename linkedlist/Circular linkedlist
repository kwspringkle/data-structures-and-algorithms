//Danh sách liên kết vòng

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int value;
	struct Node * next;
}node;

node * head;

node * makenode(int x){
	node * newnode = malloc(sizeof(node));
	newnode -> value = x;
	newnode -> next = newnode ;
	return newnode ;
}

node * addnode(node * head, int x){
	node * q = head;
	node * newnode = makenode(x);
	while(q -> next != head){
		q = q -> next;
	}
	newnode -> next = head;
	q -> next = newnode;
	return head;
}

void printlist(node *head, int k){
	node *q = head;
	for (int i = 0; i < k; i++){
		q = q->next;
	}
	printf("%d ", q -> value);
	node *q2 = q->next;
	while (q2 != q){
		printf("%d ", q2 -> value);
		q2 = q2->next;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	 for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) {
            head = makenode(arr[0]); // Initialize the head with the first element
        } else {
            head = addnode(head, arr[i]);
        }
    }
	int k;
	scanf("%d", &k);
	printlist(head, k);
}
