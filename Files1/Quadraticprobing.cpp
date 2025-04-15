#include<bits/stdc++.h>
using namespace std;

class Quadraticprobing{
    public:
    int Hsize;
    int *Htable;
    Quadraticprobing(int s){
        Hsize = s;
        Htable = new int[Hsize];
        for(int i = 0; i<Hsize;i++){
            Htable[i] = 0;
        }
    }
    void collison_handling(int val){
        //int temp = val;
        
        int Hindex = val % Hsize;
        if(Htable[Hindex] == 0){
            Htable[Hindex] = val;
        }
        else {
            int i = Hindex;
            int j = 1;
            while(Htable[i] != 0){
                i = i + (j)^2;
                j = j++;
                if(i == Hsize){
                    i = i % Hsize;
                }  
            }
            Htable[i] = val;
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
    Quadraticprobing HTable(10);
    HTable.collison_handling(29);
    HTable.collison_handling(11);
    HTable.collison_handling(154);
    HTable.collison_handling(239);
    HTable.collison_handling(143);
    HTable.collison_handling(19);
    HTable.collison_handling(101);
    HTable.collison_handling(17);
    HTable.collison_handling(111);
    HTable.collison_handling(107);
    //HTable.collison_handling(99);

    HTable.Display();
    return 0;
}
