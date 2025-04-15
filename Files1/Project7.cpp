#include<bits/stdc++.h>
using namespace std;

struct binarytree{
    int data;
    binarytree *lc;
    binarytree *rc;

    binarytree(int val){
        data = val;
        lc = NULL;
        rc =NULL;
    }
};

void preorder(struct binarytree *&root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->lc);
    preorder(root->rc);
}

void inorder(struct binarytree *&root){
    if(root==NULL){
        return;
    }
    inorder(root->lc);
    cout<<root->data<<" ";
    inorder(root->rc);
}

void postorder(struct binarytree *&root){
    if(root==NULL){
        return;
    }
    postorder(root->lc);
    postorder(root->rc);
    cout<<root->data<<" ";
}


int main(){
    struct binarytree *bt= new binarytree(1);
    bt->lc = new binarytree(2);
    bt->rc = new binarytree(3);
    bt->lc->lc = new binarytree(5);
    bt->rc->rc = new binarytree(6);
    preorder(bt);
    cout<<endl;
    inorder(bt);
    cout<<endl;
    postorder(bt);
    return 0;
}