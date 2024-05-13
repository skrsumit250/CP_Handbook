#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>adj[100100];
vector<bool>vis(100100,false);
bool DFS(int node,int par){
    vis[node]=true;
    for(auto x:adj[node]){
        if(!vis[x]){
            if(DFS(x,node))
            return true;
        }
        else if(x!=par)
        return true;
    }
    return false;
}
int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(DFS(1,0))
    cout<<"Graph has cycle\n";
    else
    cout<<"Graph does not have cycle\n";
    
    return 0;
}