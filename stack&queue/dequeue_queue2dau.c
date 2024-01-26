//Queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void push_Queue_front(int v){
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

void push_Queue_back(int v){
	Node * newNode = makeNode(v);
	if(QueueEmpty()){
		head = newNode;
		tail = newNode;
	} else {
		newNode -> prev = tail;
		tail -> next = newNode;
		tail = newNode;
	}
}

void pop_Queue_back(){
	if(QueueEmpty()){
		return;
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
}



int main(){
	int n;
	scanf("%d", &n);
	char cmd[5];
	for(int i = 0; i < n; i++){
	    scanf("%s", cmd);
	    if(strcmp(cmd, "pf") == 0){
	        int x;
	        scanf("%d", &x);
	        push_Queue_front(x);
	    } else if(strcmp(cmd, "pb") == 0){
	        int x;
	        scanf("%d", &x);
	        push_Queue_back(x);
	    } else if(strcmp(cmd, "pp_b") == 0){
	        pop_Queue_back();
	    } else if(strcmp(cmd, "f") == 0){
	        printf("%d", head -> value);
	    }
	}
}
