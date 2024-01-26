#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Node {
    int coef;
    int expo;
    struct Node* next;
} Node;

void insertNode(Node** head, int coef, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* current1 = poly1;
    Node* current2 = poly2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->expo > current2->expo) {
            insertNode(&result, current1->coef, current1->expo);
            current1 = current1->next;
        } else if (current1->expo < current2->expo) {
            insertNode(&result, current2->coef, current2->expo);
            current2 = current2->next;
        } else {
            int sum = current1->coef + current2->coef;
            insertNode(&result, sum, current1->expo);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insertNode(&result, current1->coef, current1->expo);
        current1 = current1->next;
    }
    while (current2 != NULL) {
        insertNode(&result, current2->coef, current2->expo);
        current2 = current2->next;
    }

    return result;
}

Node* abtract(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* current1 = poly1;
    Node* current2 = poly2;
    Node* currentResult = NULL;
    int count1 = 0;
    int count2 = 0;
    while (current1 != NULL) {
        count1++;
        current1 = current1->next;
    }
    while (current2 != NULL) {
        count2++;
        current2 = current2->next;
    }
    //Để trừ thì nếu như biểu thức 1 có bậc thấp hơn --> bổ sung thành bậc cao hơn với cơ số 00
    if (count1 < count2) {
        int diff = count2 - count1;
        for (int i = 0; i < diff; i++) {
            insertNode(&current1, 0, count1 + i);
        }
    }

    while (current1 != NULL && current2 != NULL) {
        if (current1->expo > current2->expo) {
            insertNode(&result, current1->coef, current1->expo);
            current1 = current1->next;
        } else if (current1->expo < current2->expo) {
            insertNode(&result, current2->coef, current2->expo);
            current2 = current2->next;
        } else {
            int sum = current1->coef - current2->coef;
            insertNode(&result, sum, current1->expo);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insertNode(&result, current1->coef, current1->expo);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertNode(&result, current2->coef, current2->expo);
        current2 = current2->next;
    }

    return result;
}

void printList(Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    Node* current = poly;
    int allZero = 1;

    while (current != NULL) {
        if (current->coef != 0) {
            allZero = 0;
            break;
        }
        current = current->next;
    }
    current = poly;

    if (allZero) {
    	return;
    }
    else{
	    while (current != NULL) {
	        printf("%d ", current->coef);
	        current = current->next;
		}
    }

    printf("\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int count(Node* poly) {
    int count = 0;
    Node* current = poly;
    int allZero = 1;

    while (current != NULL) {
        if (current->coef != 0) {
            allZero = 0;
            break;
        }
        current = current->next;
    }
    current = poly;
    if(allZero==1) printf("1 ");
    while (current != NULL) {
    	if(current->coef != 0) 
        	count++;
        current = current->next;
    }
    return count;
}

int main() {
    int numCoefs1, numCoefs2;
    int coef, expo;
    scanf("%d", &numCoefs1);
    Node* poly1 = NULL;
    int i,j;
    for (i = 0; i < numCoefs1; i++) {
        scanf("%d", &coef);
        insertNode(&poly1, coef, i);
    }
    scanf("%d", &numCoefs2);
    Node* poly2 = NULL;
    for (j = 0; j < numCoefs2; j++) {
        scanf("%d", &coef);
        insertNode(&poly2, coef, j);
    }
    char cmd[256];
    scanf("%s", cmd);
    Node* sum=NULL;
    if(strcmp(cmd,"plus")==0){
    	sum = add(poly1, poly2);
	}else if(strcmp(cmd,"minus")==0){
		sum = abtract(poly1, poly2);
	}
    int Coefs = count(sum);
    printf("%d ", Coefs);
    printList(sum);

    freeList(poly1);
    freeList(poly2);
    freeList(sum);

    return 0;
}
