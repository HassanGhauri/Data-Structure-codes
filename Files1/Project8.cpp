#include<bits/stdc++.h>
using namespace std;

struct bst{
    int data;
    bst *lc;
    bst *rc;

    bst(int val){
        data = val;
        lc = NULL;
        rc =NULL;
    }
};
bst* insertBST(bst *root,int val){
    if(root==NULL){
        return new bst(val);
    }
    if(val<root->data){
        root->lc = insertBST(root->lc,val);
    }
    else {
        root->rc = insertBST(root->rc,val);
    }
    return root;

}

void inorder(struct bst*&root){
    if(root==NULL){
        return;
    }
    inorder(root->lc);
    cout<<root->data<<" ";
    inorder(root->rc);
}
void preorder(struct bst *&root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->lc);
    preorder(root->rc);
}
void descending(struct bst *&root){
    if(root==NULL){
        return;
    }
    descending(root->rc);
    cout<<root->data<<" ";
    descending(root->lc);
    
}
bst* searchInBST(bst *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return searchInBST(root->lc,key);
    }
    return searchInBST(root->rc,key);
}
/*int min(struct bst *root){
    if(root == NULL){
        return -1;
    }
    while(root->lc != NULL){
        root=root->lc;
    }
    return root->data;
}*/
void min(struct bst *root){
    if(root == NULL){
        cout<<"tree is empty!"<<endl;
    }
    if(root->lc != NULL){
        min(root->lc);
    } else{
        cout<<root->data<<endl;
    }
}
/*int max(struct bst *root){
    if(root == NULL){
        return -1;
    }
    while(root->rc != NULL){
        root=root->rc;
    }
    return root->data;
}*/
void max(struct bst *root){
    if(root == NULL){
        cout<<"tree is empty!"<<endl;
    }
    if(root->rc != NULL){
        max(root->rc);
    }
    else{
        cout<<root->data<<endl;
    }  
    }

int main(){
    bst *root = NULL;
    root = insertBST(root,2);
    insertBST(root,4);
    insertBST(root,1);
    insertBST(root,7);
    insertBST(root,9);
    insertBST(root,8);
    min(root);
    max(root);
    /*if(searchInBST(root,10)==NULL){
        cout<<"key doesn't exist";
    } else {
        cout<<"Key exist";
    };*/
    //inorder(root);
    descending(root);
    cout<<endl;
    return 0;
}
