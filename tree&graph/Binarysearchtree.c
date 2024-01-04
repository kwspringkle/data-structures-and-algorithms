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

//Tao node moi
node * makenode(int x){
	node * newnode = malloc(sizeof(node));
	newnode -> value = x;
	newnode -> left = NULL;
	newnode -> right = NULL;
	return newnode;
}

node * root;

//Chon node lam root
void makeroot(int x){
	root = makenode(x);
}


//Chen node moi vao cay nhi phan
node * insert(node * root, int x){
	if(root == NULL) return makenode(x);
	if(x < root -> value){
		root -> left = insert(root -> left, x);
	} else if(x >= root -> value){
		root -> right = insert(root -> right, x);
	}
	return root;
}

//Duyet cay thu tu truoc
void printtree_preorder(node * root){
	if(root != NULL){
		printf("%d ", root -> value);
		printtree_preorder(root -> left);
		printtree_preorder(root -> right);
	}
}

//Duyet cay thu tu giua
void printtree_inorder(node * root){
	if(root != NULL){
		printtree_inorder(root -> left);
		printf("%d ", root -> value);
		printtree_inorder(root -> right);
	}
}

//Duyet cay thu tu sau
void printtree_postorder(node * root){
	if(root != NULL){
		printtree_postorder(root -> left);
		printtree_postorder(root -> right);
		printf("%d ", root -> value);
	}
}

//Check xem 1 node co la la khong
int isleaf(node * leaf){
	if(leaf == NULL) return 0;
	if(leaf -> left == NULL && leaf -> right == NULL) return 1;
	else return 0;
}

//Dem so la cua 1 cay
int countleaves(node * leaf){
	if(leaf == NULL) return 0;
	if(isleaf(leaf)) return 1;
	else return countleaves(leaf -> left) + countleaves(leaf -> right);
}


int max(int a, int b){
	if(a < b) return b;
	else return a;
}

//Tinh do cao cua cay nhi phan
int treelevel(node * x){
	if(x == NULL) return -1;
	return 1 + max(treelevel(x -> left), treelevel(x -> right));
}

//Kiem tra xem cay nhi phan co la cay AVL khong
int checkAVL(node * x){
	if(x == NULL) return 1;
	if(abs(treelevel(x -> left) - treelevel(x -> right)) > 1) return 0;
	else return checkAVL(x -> left) && checkAVL(x -> right);
}

//Tim kiem tren cay nhi phan node co gia tri x
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

//Dem so node cua 1 cay
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

//Tra ve cha cua 1 node
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

//Ky thuat xoay phai bien cay nhi phan lech trai thanh cay AVL
node *turnRight(node *a){
	node *b = a->left;
	node *d = b->right;
	a->left = d;
	b->right = a;
	return b;
}

//Ky thuat xoay trai bien cay nhi phan lech phai thanh cay AVL
node *turnLeft(node *a){
	node *b = a->right;
	node *c = b->left;
	a->right = c;
	b->left = a;
	return b;
}


int main(){
//Kiem thu ham
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




