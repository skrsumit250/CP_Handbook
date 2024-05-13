#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>adj[100100];
vector<int>ver(n+1,0);
void DFS(int node,int par){
    ver[node]=1;
    for(int v:adj[node]){
        if(v!=par){
            DFS(v,node);
            ver[node]+=ver[v];
        }
    }
}
int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1,0);
    for(int i=1;i<=n;i++)
    cout<<ver[i]<<" ";
    return 0;
}