#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>adj[100100];
void DFS(int node,int par){
    cout<<node<<" ";
    for(int v:adj[node]){
        if(v!=par){
            DFS(v,node);
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
    return 0;
}