#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>adj[100100];
vector<bool>vis(100100,false);
vector<int>color(100100);
bool DFS(int node,int col){
    vis[node]=true;
    color[node]=col;
    for(auto x:adj[node]){
        if(!vis[x]){
            if(!DFS(x,col^1))
            return false;
        }
        else if(color[x]==color[node])
        return false;
    }
    return true;
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
    cout<<"Graph is Bipartite\n";
    else
    cout<<"Graph is not Bipartite\n";
    
    return 0;
}