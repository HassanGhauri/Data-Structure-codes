#include<bits/stdc++.h>
using namespace std;


int addressRM(int I[], int S[],int n){
    int Slot = 0;
    for(int i=0; i<=n-1 ; i++)
    {
        int prod = 1;
        for (int s = i+1 ; s <= n-1 ; s++){
        prod = prod * S[s];
        }
        Slot=Slot + I[i] * prod;
    }
    return Slot;
}
int main(){
    int I []= {3,3};
    int S []= {4,4};
    cout <<addressRM(I,S,2);
    return 0;
}

