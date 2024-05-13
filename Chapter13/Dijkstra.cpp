#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,src;
    cin>>n>>m>>src;
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<bool>vis(n+1,false);
    vector<int>dis(n+1,1e9);
    dis[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        auto curr=pq.top().second;
        pq.pop();
        if(vis[curr])
        continue;

        vis[curr]=true;
        for(auto x:adj[curr]){
            if(dis[curr]+x.second<dis[x.first]){
                dis[x.first]=dis[curr]+x.second;
                pq.push({dis[x.first],x.first});
            }
        }
    }
    for(ll i=1;i<=n;i++)
    cout<<src<<"-> "<<i<<" = "<<dis[i]<<"\n";
    return 0;
}
// 5 6 1
// 3 4 6
// 3 2 2
// 2 1 5
// 1 5 1
// 4 5 2
// 4 1 9