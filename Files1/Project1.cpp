#include<bits/stdc++.h>
using namespace std;

struct ETNode {
    char ch; // operator/operand
    struct ETNode *LC , *RC;
};
int IsOperator(char c)
{
    if(c=='^') return 3;
    if(c=='*') return 2;
    if(c=='/') return 2;
    if(c=='%') return 2;
    if(c=='+') return 1;
    if(c=='-') return 1;
    if(c=='(') return 4;
    if(c==')') return 4;
    return 0;
}

void Inorder(struct ETNode *node){
    if(node == NULL){
    return;
    }
    Inorder(node->LC);
    cout<<node->ch<<" ";
    Inorder(node->RC);
}
void Preorder(struct ETNode *node){
    if(node==NULL){
    return;
    }
    cout<<node->ch<<" ";
    Preorder(node->LC);
    Preorder(node->RC);
}
void Postorder(struct ETNode *node){
    if(node==NULL){
    return;
    }
    Postorder(node->LC);
    Postorder(node->RC);
    cout<<node->ch<<" ";
}


int main(){
    struct ETNode *stack[10];
    int top=-1;
    struct ETNode *root=NULL;
    char infix[] = "AB+CD-*";
    for(int i =0 ; i < strlen(infix) ; i++) {
    struct ETNode *temp = new ETNode();
    temp->ch = infix[i];
    temp->LC = temp-> RC = NULL;
    if(IsOperator(infix[i])==0){
    stack[++top] = temp;
    } // operand

    else // operator
    {
    temp->RC = stack[top--];
    temp->LC = stack[top--];
    stack[++top] = temp;
    }
    }//end of loop
    root = stack[top--];
    //Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    //Postorder(root);
    return 0;
}
