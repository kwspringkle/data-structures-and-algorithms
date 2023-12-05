//Queue
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node * prev;
	struct Node * next;
}Node;

Node * head = NULL;
Node * tail = NULL;

Node * makeNode(int v){
	Node * newNode = malloc(sizeof(Node));
	newNode -> value = v;
	newNode -> next = NULL;
	newNode -> prev = NULL;
	return newNode;
}

int QueueEmpty(){
	return head == NULL && tail == NULL;
}

void push_Queue(int v){
	Node * newNode = makeNode(v);
	if(QueueEmpty()){
		head = newNode;
		tail = newNode;
	} else {
		newNode -> next = head;
		head -> prev = newNode;
		head = newNode;
	}
}

int pop_Queue(){
	if(QueueEmpty()){
		printf("Error");
	}
	int v = tail -> value;
	Node * tmp = tail;
	tail = tail -> prev;
	if(tail != NULL){
		tail -> next = NULL;
	} else {
		head = NULL;
	}
	free(tmp);
	return v;
}

void printlist(){ //In ngu?c 
	for(Node * current = tail; current != NULL; current = current -> prev ){
		printf("%d ", current -> value);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		push_Queue(x);
	}
	int m = pop_Queue();
	printlist();
	printf("%d", m);
}
