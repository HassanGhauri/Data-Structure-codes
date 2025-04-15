#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin >> n >> m;
    vector<vector<int>> adjl(n);
    vector<int> indeg(n,0);
    cout<<"Enter data :"<<endl;
    for(int i = 0; i<m;i++){
        int u,v;
        cin>>u>>v;

        adjl[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
    for(int i=0;i<n;i++){
        if(indeg[i] == 0){
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";

        for(auto it : adjl[x]){
            indeg[it]--;
            if(indeg[it] == 0){
                pq.push(it);
            }
        }
    }
    return 0;
    
}