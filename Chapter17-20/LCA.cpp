// Author:BlueSkull
// Created At: 02.10.2024  15:00:52
#include<bits/stdc++.h>
using namespace std;

// #include "Algo/utils.hpp"
// ifstream inputFile("input.txt");
// ofstream outputFile("output.txt");

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define F first
#define S second
#define vii vector<pair<int,int>>
const int mod=1e9+7;
const ll INFLL=1e9+15;
// Observation: 2^n = 2^(n-1)+2^(n-1);
// Approach: Find Lowest Common Ancestor using Binary Lifting
//           let k(2)=10100,jump when ith bit is set
//           node=9, first jump will be at 2nd bit then 4th bit.
int n,q;
vi adj[200100];
int dis[200100];
int bin[200100][23];

void DFS(int node,int par,int l){
    dis[node]=l;
    for(auto x:adj[node]){
        if(x==par)
        continue;

        DFS(x,node,l+1);
    }
}
void BinaryLifting(){
    for(int j=1;j<23;j++){
        for(int i=1;i<=n;i++){
            int p=bin[i][j-1]; // First Jump
            if(p!=-1)
            bin[i][j]=bin[p][j-1]; // Second Jump
        }
    }
}
int getCommonAncestor(int a,int b){
    if(dis[a]<dis[b])
    swap(a,b);

    int diff=dis[a]-dis[b];
    for(int i=0;i<23;i++){
        if(diff&(1<<i))
        a=bin[a][i];
    }
    if(a==b)
    return a;

    for(int i=22;i>=0;i--){
        if(bin[a][i]!=bin[b][i]){
            a=bin[a][i];
            b=bin[b][i];
        }
    }
    return bin[a][0];
}
void solve(){
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        bin[i][0]=a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    DFS(1,-1,0);
    BinaryLifting();
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<getCommonAncestor(a,b)<<"\n";
    }
}
int main(){

    //#ifndef BlueSkull
    //	freopen("Error.txt","w",stderr);
    //#endif
    fastio();
    solve();
    return 0;
}