#include <iostream>
#include <vector>
using namespace std;

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

int main(){
    int n; cin >> n; vector<int> V(n);
    for(int& i : V){ cin >> i; }
    
    int idx; cin >> idx;
    heapDown(V,idx,n);
    for(int i=0; i<n; i++){
        cout << V[i];
        if(i<n-1){ cout << " ";}
    }
    cout << endl;
    return 0;
}
