#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct tree {
	int value;
	struct tree * left;
	struct tree * right;
};

typedef struct tree  node;

node * makenode(int x){
	node * newnode = malloc(sizeof(node));
	newnode -> value = x;
	newnode -> left = NULL;
	newnode -> right = NULL;
	return newnode;
}

node * root;

void makeroot(int x){
	root = makenode(x);
}

node * insert(node * root, int x){
	if(root == NULL) return makenode(x);
	if(x < root -> value){
		root -> left = insert(root -> left, x);
	} else if(x >= root -> value){
		root -> right = insert(root -> right, x);
	}
	return root;
}

void printtree_preorder(node * root){
	if(root != NULL){
		printf("%d ", root -> value);
		printtree_preorder(root -> left);
		printtree_preorder(root -> right);
	}
}

void printtree_inorder(node * root){
	if(root != NULL){
		printtree_inorder(root -> left);
		printf("%d ", root -> value);
		printtree_inorder(root -> right);
	}
}

void printtree_postorder(node * root){
	if(root != NULL){
		printtree_postorder(root -> left);
		printtree_postorder(root -> right);
		printf("%d ", root -> value);
	}
}

int isleaf(node * leaf){
	if(leaf == NULL) return 0;
	if(leaf -> left == NULL && leaf -> right == NULL) return 1;
	else return 0;
}

int countleaves(node * leaf){
	if(leaf == NULL) return 0;
	if(isleaf(leaf)) return 1;
	else return countleaves(leaf -> left) + countleaves(leaf -> right);
}

int max(int a, int b){
	if(a < b) return b;
	else return a;
}

int treelevel(node * x){
	if(x == NULL) return -1;
	return 1 + max(treelevel(x -> left), treelevel(x -> right));
}

int checkAVL(node * x){
	if(x == NULL) return 1;
	if(abs(treelevel(x -> left) - treelevel(x -> right)) > 1) return 0;
	else return checkAVL(x -> left) && checkAVL(x -> right);
}

node *find (node * root, int x){
    if(root == NULL) return NULL;
    if(root -> value == x) return root;
    node * p = root -> left;
    while(p != NULL){
        node * h = find(p, x);
        if(h != NULL) return h;
        p = p -> right;
    }
    return NULL;
}

int count(node * root){
    if(root == NULL) return 0;
    int count = 1;
    node * p = root -> left;
    while(p != NULL){
        count += count(p);
        p = p -> right;
    }
    return count;
}

node * parent(node * p, node * root){
    if(root == NULL) return NULL;
    node * q = root -> left;
    while(q != NULL){
        if(p == q) return root;
        node * pp = parent(p, q);
        if(pp != NULL) return pp;
        q = q -> right;
    }
    return NULL;
}

node *turnRight(node *a){
	node *b = a->left;
	node *d = b->right;
	a->left = d;
	b->right = a;
	return b;
}

node *turnLeft(node *a){
	node *b = a->right;
	node *c = b->left;
	a->right = c;
	b->left = a;
	return b;
}


int main(){
	int n;
	scanf("%d", &n);
	int r;
	scanf("%d", &r);
	makeroot(r);
	int inp;
	for(int i = 1; i < n; i++){
		scanf("%d", &inp);
		root = insert(root, inp);
	}
	printtree_inorder(root); printf("\n");
	printtree_preorder(root); printf("\n");
	printtree_postorder(root); printf("\n");
	printf("%d\n", countleaves(root));
	int x = checkAVL(root);
	if(x == 1){
		printf("true\n");
	} else {
		printf("false\n");
	}
}




