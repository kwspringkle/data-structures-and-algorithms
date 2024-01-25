#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
int size(node *head){
    int cnt = 0;
    while(head != NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void exportListNode(node *head){
    node *cur = head;
    while(cur->next != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("%d", cur->data);
}
node *makenode(int x){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void pushback(node **head, int x){
    node *newnode = makenode(x);
    node *tmp = (*head);
    if(tmp == NULL){
        *(head) = newnode;
        return;
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newnode;
}
void check(node **head){
    node *cur = *head;
    if(cur == NULL){
        return;
    }
    while(cur->next != NULL){
        if(cur->data == cur->next->data){
            node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
        else{
            cur = cur->next;
        }
    }
}
void sort(node **head){
    for(node *i = (*head); i != NULL; i = i->next){
        node *min = i;
        for(node *j = i->next; j != NULL; j = j->next){
            if(min->data > j->data){
                min = j;
            }
        }
        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}
int main(){
    node *head = NULL;
    char k = '\n';
    while(1){
    int a;
        if(scanf("%d", &a) == EOF) break;
        pushback(&head, a);
    if(getchar() == k) break;
    }
    check(&head);
    sort(&head);
    exportListNode(head);
}
