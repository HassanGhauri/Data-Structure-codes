#include<bits/stdc++.h>
using namespace std;



#define vi vector<int>
#define vvi vector<vi>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main(){
    int n,m;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin >> n >> m;

    vvi adjm(n+1,vi(n+1,0));

    cout<<"Enter data:"<<endl;
    rep(i,0,m)
    {
        int x,y;
        cin >> x >> y;

        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout<< "adjacency matrix of above graph is given by: "<<endl;

    rep(i,0,n)
    {
        cout << i << " : ";
        rep(j,0,n)
        {
            cout<< adjm[i][j] <<" ";
        }
        cout<<endl;
    }

    //if(adjm[3][2]==1){
      //  cout<<"there is an edge"<<endl;
    //}
    //else{
     //   cout<<"no edge!"<<endl;
    //}
    return 0;
}