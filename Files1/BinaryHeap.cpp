#include<bits/stdc++.h>
using namespace std;

void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}
class MinHeap{
    public:
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int cap){
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    void linearSearch(int val){
        for(int i =0; i < heap_size; i++){
            if(harr[i]==val){
                cout<<"Value Found!";
                return;
            }
        }
        cout<<"Value Not Found!";
    }
    void printArray(){
        for(int i = 0; i < heap_size;i++){
            cout<<harr[i]<<" ";
        }cout<<endl;
    }
    int height(){
        return ceil(log2(heap_size + 1)) - 1;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return(2*i + 1);
    }
    int right(int i){
        return (2*i +2);
    }
    void insertKey(int k){
        if(heap_size == capacity){
            cout << "\n Overflow: could not insert Key\n";
            return;  
        }

        heap_size++;
        int i = heap_size -1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i]){
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
    void MinHeapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap_size && harr[l] < harr[i]){
            smallest = l;
        }
        if(r < heap_size && harr[r] < harr[smallest]){
            smallest = r;    
        }
        if(smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin(){
        if(heap_size <= 0){
            return INT_MAX;
        }
        if(heap_size == 1){
            heap_size--;
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MinHeapify(0);
        return root;
    }
    void decreaseKey(int i, int new_val){
        harr[i] = new_val;
        while(i != 0 && harr[parent(i)] > harr[i]){
            swap(harr[i],harr[parent(i)]);
            i = parent(i);
        }
    }
    void deleteKey(int i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }

};

int main(){
    MinHeap obj(7);
    obj.insertKey(2);
    obj.insertKey(4);
    obj.insertKey(1);
    obj.insertKey(7);
    obj.insertKey(6);
    obj.printArray();
    obj.deleteKey(7);
    obj.printArray();

    return 0;
}