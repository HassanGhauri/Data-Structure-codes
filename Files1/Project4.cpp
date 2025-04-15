#include<bits/stdc++.h>
using namespace std;

#define n 20
class Queue{
     int *arr;
     int front;
     int rear;

     public:
     Queue(){
         arr = new int[n];
         front = -1;
         rear = -1;
     }

     void enqueue(int val){
         if(rear==n-1){
            cout<<"Queue Overflow!"<<endl;
            return;
         }
         rear++;
         arr[rear] = val;

         if(front==-1){
            front++;
         }
     }

     void dequeue(){
         if(front==-1 || front>rear){
            cout<< "Queue Underflow!"<<endl;
            return;
         }

         front++;
     }

     int peek(){
         if(front==-1 || front>rear){
            cout<< "Queue empty!"<<endl;
            return-1;
         }

         return arr[front];
     }
};



int main(){
     Queue q;
     q.enqueue(1);
     q.enqueue(2);
     q.enqueue(3);
     //cout<<q.peek()<<endl;
     q.dequeue();
     cout<<q.peek()<<endl;



     return 0;
}
