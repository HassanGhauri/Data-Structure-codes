#include<bits/stdc++.h>
using namespace std;

class que{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
};

int main(){
    que Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    cout<<Q.pop();
    Q.push(5);
    return 0;
}