#include<bits/stdc++.h>
using namespace std;

class linearprobing{
    public:
    int Hsize;
    int *Htable;
    linearprobing(int s){
        Hsize = s;
        Htable = new int[Hsize];
        for(int i = 0; i<Hsize;i++){
            Htable[i] = 0;
        }
    }
    void collison_handling(int val){
        int temp = val;
        
        int Hindex = val % Hsize;
        if(Htable[Hindex] == 0){
            Htable[Hindex] = val;
        }
        else {
            int i = Hindex;
            while(Htable[i] != 0){
                i++;
                if(i == Hsize){
                    i = (i+1) % Hsize;
                }
                
            }

            Htable[i] = temp;
        }
    }
    void Display(){
        for(int i = 0;i<Hsize;i++){
            cout<<"( "<<i<<" )"<<" ";
            cout<<Htable[i]<<endl;
        }
    }
};

int main(){
    linearprobing HTable(10);
    HTable.collison_handling(52);
    HTable.collison_handling(80);
    HTable.collison_handling(19);
    HTable.collison_handling(191);
    HTable.collison_handling(182);
    HTable.collison_handling(71);
    HTable.collison_handling(99);
    HTable.Display();
    return 0;
}
