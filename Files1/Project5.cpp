#include<bits/stdc++.h>
using namespace std;

int IsOperator(char c)  
{if(c=='^') return 3;    
if(c=='*') return 2;       
if(c=='/') return 2;       
if(c=='%') return 2;       
if(c=='+') return 1;       
if(c=='-') return 1;       
if(c=='(') return 4;       
if(c==')') return 4;              
return 0;    
}

int infixtopostfix(char infix[],char postfix[]){
    char stack[strlen(infix)]; int top=-1;
    int j = 0;
    for(int i=0 ; i<strlen(infix) ; i++)
    {
        if(infix[i] == '(')
        {
            stack[++top] = '(';
            continue;
        }
        if(infix[i] == ')')
        {
            while(stack[top]!='('){
                postfix[j++] =  stack[top--];
            }
            top--;    // to remove ')'
            continue;
        }


        if(IsOperator(infix[i]) == 0)
        {
            postfix[j++] = infix[i];               
        }
        else
        { // operator
            if(stack[top] == '(' || top==-1)
            {
                stack[++top] = infix[i];
                continue;
            }
            while(top != -1 && IsOperator(infix[i]) <= IsOperator(stack[top])){
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
            }
            // end of else
    } // end of loop
    while(top >= 0){
        if(stack[top] == '('){
            continue;
        }
        postfix[j++] = stack[top--];
        }
                
        postfix[j++] = '\0';
        printf("%s", postfix);
        return 0;
}


int main(){
    char infix[]="a+b*(c/d)^2-x+y";
    char postfix[]="";
    infixtopostfix(infix,postfix);
    return 0;
}
