#include<bits/stdc++.h>
using namespace std;

//#define n 100

class Stack{
     int *array;
     int top;
     int n;

     public:
     Stack(int size){
         n = size;
         array = new int[n];
         top = -1;
     }
     void Push(int val){

         if(top==n-1){
            cout<<"Stack Overflow!"<<endl;
            return;
         }
    
         top++;
         array[top] = val;
     }
     void Pop(){
         if(top == -1){
            cout<<"Stack Underflow!"<<endl;
            return;
         }
         top--;
     }
     int Top(){
         if(top == -1){
            cout<<"No element in stack!"<<endl;
            return-1;
         }
         return array[top];
     }
};

int main(){
     Stack st(5);
     st.Push(1);
     st.Push(2);
     st.Push(3);
     cout<<st.Top()<<endl;
     st.Pop();
     cout<<st.Top()<<endl;
     st.Pop();
     st.Pop();
     st.Pop();
     return 0;
}
