#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,pair<int,int>>>vp;
vector<int>link(100100),deg(100100);
vector<pair<int,int>>adj[100100];
vector<bool>vis(100100,false);
void DFS(int node){
    vis[node]=true;
    for(auto x:adj[node]){
        if(!vis[x.first]){
            cout<<node<<" "<<x.first<<" "<<x.second<<endl;
            DFS(x.first);
        }
    }
}
int find(int x){
    while(x!=link[x])
    x=link[x];

    return x;
}
void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(deg[a]<deg[b])
    swap(a,b);

    deg[a]+=deg[b];
    link[b]=a;
}
int main(){
    ifstream inputFile("input.txt");
    inputFile>>n>>m;
    vp.clear();
    for(int i=0;i<m;i++){
        int a,b,c;
        inputFile>>a>>b>>c;
        vp.push_back({c,{a,b}});
    }
    sort(vp.begin(),vp.end());
    
    for(int i=1;i<=n;i++){
        link[i]=i;
        deg[i]=0;
        adj[i].clear();
    }
    int min_weight=0;
    for(int i=0;i<m;i++){
        int u=vp[i].second.first,v=vp[i].second.second,w=vp[i].first;
        if(find(u)!=find(v)){
            unite(u,v);
            min_weight+=w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
    }
    cout<<"Minimum Weight= "<<min_weight<<endl;
    DFS(1);
    return 0;
}
// 5 8
// 5 6 2
// 1 2 3
// 3 6 3
// 1 5 5
// 2 3 5
// 2 5 6
// 4 6 7
// 3 4 9