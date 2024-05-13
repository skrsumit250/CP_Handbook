#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct TREE{
    int N;
    vector<int>bits;
    void init(int n){
        N=n;
        bits.assign(n+1,0);
    }
    void update(int idx,int val){
        while(idx<=N){
            bits[idx]=bits[idx]+val;
            idx=idx+(idx&(-idx));
        }
    }
    int get(int idx){
        int res=0;
        while(idx>0){
            res=res+bits[idx];
            idx=idx-(idx&(-idx));
        }
        return res;
    }
};
int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int n=10;
    vector<int>v={1,2,3,4,5,6,7,8,9,10};
    TREE BIT;
    BIT.init(n);
    for(int i=0;i<n;i++){
        BIT.update(i+1,v[i]);
    }
    cout<<BIT.get(10)-BIT.get(4);
    return 0;
}