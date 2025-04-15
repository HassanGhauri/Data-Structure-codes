#include<bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define vvi vector<vi>
#define rep(i,a,b) for(int i=a;i<b;i++)


int main(){
    int n,m;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin >> n >> m;
    vi adjl[n];
    cout<<"Enter data:"<<endl;
    rep(i,0,m)
    {
        int x,y;
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    cout<< "adjacency list of above graph is given by: "<<endl;
    rep(i,0,m){
        cout<<i<<"->";
        for(int x:adjl[i]){
            cout<<x<<" ";
        }cout<<endl;
    }
    return 0;
}