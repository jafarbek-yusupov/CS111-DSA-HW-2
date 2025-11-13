#include <iostream>
#include <vector>
#include <string>
#define pb push_back
using namespace std;
typedef string str;


class MaxPriorityQueue{
private:
    vector<int> data;
public:
    void insert(int x){ data.pb(x);}
    void size(){ cout << data.size() << endl;}

    void getMax(){
        if(data.empty()){ cout << "EMPTY\n"; return;}
        int maxv = data[0];
        for(int i=1; i<data.size(); i++){
            maxv = data[i]>maxv ? data[i] : maxv;
        }
        cout << maxv << endl;
    }
    
    void extractMax(){
        if(data.empty()){ cout << "EMPTY\n"; return;}
        int maxv = data[0], maxIdx = 0;
        for(int i=1; i<data.size(); i++){
            if(data[i]>maxv){
                maxv=data[i];
                maxIdx=i;
            }
        }
        cout << maxv << endl;
        data[maxIdx] = data[data.size()-1];
        data.pop_back();
    }
};

int main(){
    int n; cin >> n;
    MaxPriorityQueue pq;
    for(int i=0; i<n; i++){
        str cmd; cin >> cmd;
        if(cmd=="insert"){ int x; cin >> x; pq.insert(x); }
        else if(cmd=="size"){ pq.size();} 
        else if(cmd=="get"){
            str maxwrd; cin >> maxwrd;
            pq.getMax();
        }
        else if(cmd=="extract"){
            str maxwrd; cin >> maxwrd;
            pq.extractMax();
        }
    }    
    return 0;
}
