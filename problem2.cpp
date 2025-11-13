#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

class MinHeap{
private:
    vector<int> heap;
    int heapSize;
    void heapDown(vector<int>& V, int i, int n){
        while(true){
            int left = 2*i+1;
            int right = left+1;
            int minv = i;
            
            if(left<n && V[left]<V[minv]){ minv = left;}
            if(right<n && V[right]<V[minv]){ minv = right;}
            if(minv==i){ break;}

            swap(V[i],V[minv]);
            i=minv;
        }
    }
    
public:
    MinHeap(vector<int>& vec) : heap(vec), heapSize(vec.size()){
        for(int i=(heapSize/2)-1; i>=0; i--){ heapDown(heap, i, heapSize);}
    }
    
    bool isEmpty(){ return heapSize == 0;}
    
    int extractMin(){
        if(heapSize<=0){ return -1;}
        int minv = heap[0];
        heap[0] = heap[heapSize-1]; heapSize--;
        if(heapSize>0){ heapDown(heap, 0, heapSize);}
        return minv;
    }
};

vector<int> heapSort(vector<int>& v){
    MinHeap minHeap(v); vector<int> srtd;
    while(!minHeap.isEmpty()){ srtd.pb(minHeap.extractMin());}
    return srtd;
}

int main(){
    int n; cin>>n;    
    vector<int> v(n); for(int& i: v){ cin >> i;}
    vector<int> sorted = heapSort(v);
    for(int i=0; i<n; i++){
        cout << sorted[i];
        if(i<n-1){ cout << " ";}
    }
    cout << endl;
    return 0;
}
