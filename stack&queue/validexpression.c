#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

typedef struct stacknode {
    char value;
    struct stacknode* next;
} Node;

Node* top;

Node* makeNode(char x) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}

void initstack() {
    top = NULL;
}

int stackEmpty() {
    return top == NULL;
}

void push(char v) {
    Node* newNode = makeNode(v);
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (stackEmpty()) {
        return '\0';  // Return a special character (e.g., '\0') to indicate an empty stack
    }
    char v = top->value;
    Node* tmp = top;
    top = top->next;
    free(tmp);
    return v;
}

int isValidExpression(const char* str) {
    initstack();
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (stackEmpty()) {
                return 0;  
            }

            char openBracket = pop();
            if ((openBracket == '(' && str[i] != ')') ||(openBracket == '[' && str[i] != ']') ||(openBracket == '{' && str[i] != '}')) {
                return 0; 
            }
        }
    }

    return stackEmpty(); 
}

int main() {
    char str[MAX];
    fgets(str, MAX, stdin);

    if (isValidExpression(str)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}
