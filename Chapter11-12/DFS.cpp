#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>adj[100100];
vector<bool>vis(100100,false);
void DFS(int node){
    vis[node]=true;
    cout<<node<<" ";
    for(auto x:adj[node]){
        if(!vis[x])
        DFS(x);
    }
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
    DFS(1);
    return 0;
}