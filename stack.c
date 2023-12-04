#include <stdio.h>
#include <stdlib.h>

//Có thể hiểu stack: danh sách liên kết đơn với con trỏ head nằm trên cùng,
//Tiếp theo bên dưới là các node và cuối cùng là NULL

typedef struct stacknode{
	int value;
	struct stacknode * next;
}Node;
Node * top;

Node * makeNode(int x){
	Node * newNode = malloc(sizeof(Node));
	newNode -> value = x;
	newNode -> next = NULL;
	return newNode;
}

void initstack(){
	top = NULL;
}

int stackEmpty(){
	return top == NULL;
}

void push(int v){
	Node * newNode = makeNode(v);
	newNode -> next = top;
	top = newNode;
}

int pop(){
	if(stackEmpty()) {
		printf("Cannot pop\n");
	}
	int v = top -> value;
	Node * tmp = top;
	top = top -> next;
	free(tmp);
	return v;
}


