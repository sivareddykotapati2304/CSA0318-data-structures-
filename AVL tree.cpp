#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key, height;
    struct Node *left, *right;
};

int h(struct Node* n){ return n ? n->height : 0; }
int max(int a,int b){ return a>b?a:b; }

struct Node* newNode(int k){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->key=k; n->left=n->right=NULL; n->height=1; return n;
}

struct Node* rightRotate(struct Node* y){
    struct Node* x=y->left; struct Node* T=x->right;
    x->right=y; y->left=T;
    y->height=max(h(y->left),h(y->right))+1;
    x->height=max(h(x->left),h(x->right))+1;
    return x;
}
struct Node* leftRotate(struct Node* x){
    struct Node* y=x->right; struct Node* T=y->left;
    y->left=x; x->right=T;
    x->height=max(h(x->left),h(x->right))+1;
    y->height=max(h(y->left),h(y->right))+1;
    return y;
}
int balance(struct Node* n){ return n? h(n->left)-h(n->right):0; }

struct Node* insert(struct Node* n,int k){
    if(!n) return newNode(k);
    if(k<n->key) n->left=insert(n->left,k);
    else if(k>n->key) n->right=insert(n->right,k);
    else return n;
    n->height=1+max(h(n->left),h(n->right));
    int b=balance(n);
    if(b>1&&k<n->left->key) return rightRotate(n);
    if(b<-1&&k>n->right->key) return leftRotate(n);
    if(b>1&&k>n->left->key){ n->left=leftRotate(n->left); return rightRotate(n); }
    if(b<-1&&k<n->right->key){ n->right=rightRotate(n->right); return leftRotate(n); }
    return n;
}

struct Node* minNode(struct Node* n){ while(n->left) n=n->left; return n; }

// ?? Renamed from delete ? deleteNode
struct Node* deleteNode(struct Node* r,int k){
    if(!r) return r;
    if(k<r->key) r->left=deleteNode(r->left,k);
    else if(k>r->key) r->right=deleteNode(r->right,k);
    else{
        if(!r->left||!r->right){
            struct Node* t=r->left?r->left:r->right;
            if(!t){ t=r; r=NULL; } else *r=*t;
            free(t);
        } else {
            struct Node* t=minNode(r->right);
            r->key=t->key;
            r->right=deleteNode(r->right,t->key);
        }
    }
    if(!r) return r;
    r->height=1+max(h(r->left),h(r->right));
    int b=balance(r);
    if(b>1&&balance(r->left)>=0) return rightRotate(r);
    if(b>1&&balance(r->left)<0){ r->left=leftRotate(r->left); return rightRotate(r);}
    if(b<-1&&balance(r->right)<=0) return leftRotate(r);
    if(b<-1&&balance(r->right)>0){ r->right=rightRotate(r->right); return leftRotate(r);}
    return r;
}

struct Node* search(struct Node* r,int k){
    if(!r||r->key==k) return r;
    return k<r->key?search(r->left,k):search(r->right,k);
}

void inorder(struct Node* r){
    if(r){ inorder(r->left); printf("%d ",r->key); inorder(r->right); }
}

int main(){
    struct Node* root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);

    printf("Inorder: "); inorder(root);

    root=deleteNode(root,40);
    printf("\nAfter delete 40: "); inorder(root);

    printf(search(root,25)?"\nFound 25\n":"\nNot Found 25\n");
    return 0;
}

