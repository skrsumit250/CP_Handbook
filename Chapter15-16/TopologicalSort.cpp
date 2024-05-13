#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,m;
vector<int>adj[100100];
vector<int>vis(100100,0);
vector<int>topo;
bool flag=true;
void TOPO(int node){
    if(!flag)
    return;

    vis[node]=1;
    for(auto x:adj[node]){
        if(vis[x]==0)
        TOPO(x);
        else if(vis[x]==1){
            flag=false;
            cout<<"Detect Cycle\n";
            return;
        }
    }
    vis[node]=2;
    topo.push_back(node);
}
int main(){
    ifstream inputFile("input.txt");
    inputFile>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        inputFile>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0)
        TOPO(i);
    }
    if(flag){
        for(int i=n-1;i>=0;i--)
        cout<<topo[i]<<" ";
    }
    return 0;
}
// Case I
// 6 7
// 1 2
// 2 3
// 3 6
// 4 1
// 4 5
// 5 2
// 5 3

// Case II
// 6 7
// 1 2
// 2 3
// 3 6
// 4 1
// 4 5
// 5 2
// 3 5

// Case II
// 5 5
// 1 2
// 2 4
// 4 5
// 3 4
// 3 5