//Encode string: for example : aaaaccccbbb -> a4c4b3, using stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stacknode {
    char letter;
    int count;
    struct stacknode* next;
} Node;

Node* top = NULL;  // Initialize top to NULL

int stackEmpty() {
    return top == NULL;
}

Node* makeNode(char c) {
    Node* newNode = malloc(sizeof(Node));
    newNode->letter = c;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

void push(char c) {
    if (stackEmpty() || top->letter != c) {
        Node* newNode = makeNode(c);
        newNode->next = top;
        top = newNode;
    } else {
        top->count++;
    }
}

void printlist(){
    Node * q = top;
    while(q != NULL){
        printf("%c%d",q -> letter, q ->count );
        q = q -> next;
    }
}

void pop() {
    if (stackEmpty()) {
        printf("cannot pop\n");
        return;
    }

    char v = top->letter;
    int n = top->count;
    Node* tmp = top;
    top = top->next;
    free(tmp);
    printf("%c%d", v, n);
}

int main() {
    char s[100];
   // fgets(s, sizeof(s), stdin);
    scanf("%s", s);
    for (int i = strlen(s)-1; i >= 0; i--) {
        push(s[i]);
    }
    
    printlist();
   
    return 0;
}
