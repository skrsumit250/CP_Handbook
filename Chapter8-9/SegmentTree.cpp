#include<bits/stdc++.h>
using namespace std;
struct Tree{
    int n;
    vector<int>ST;
    void build(vector<int>&v){
        n=v.size();
        ST.assign(2*n,0);
        for(int i=0;i<n;i++){
            ST[n+i]=v[i];
        }
        for(int i=n-1;i>0;i--){
            ST[i]=ST[2*i]+ST[2*i+1];
        }
    }
    int get(int a,int b){
        int res=0;
        a=a+n;
        b=b+n;
        while(a<=b){
            if(a%2==1){
                res=res+ST[a];
                a++;
            }
            if(b%2==0){
                res=res+ST[b];
                b--;
            }
            a=a/2;
            b=b/2;
        }
        return res;
    }
    void update(int idx,int val){
        idx=idx+n;
        ST[idx]=val;
        while(idx>1){
            idx=idx/2;
            ST[idx]=ST[2*idx]+ST[2*idx+1];
        }
    }
};
int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=6;
    vector<int>v={5,8,6,3,2,7};
    Tree segTree;
    segTree.build(v);
    cout<<segTree.get(2,4)<<endl;
    segTree.update(2,10);
    cout<<segTree.get(2,4)<<endl;
    return 0;
}