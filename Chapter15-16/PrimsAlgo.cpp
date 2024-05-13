#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,m;
vector<pii>adj[100100];
vector<bool>vis(100100,false);
int main(){
    ifstream inputFile("input.txt");
    inputFile>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        inputFile>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    int res=0;
    pq.push({0,1});
    while(!pq.empty()){
        int u=pq.top().second,w=pq.top().first;
        pq.pop();
        if(!vis[u]){
            res+=w;
            vis[u]=true;
            for(auto v:adj[u]){
                if(!vis[v.first]){
                    pq.push({v.second,v.first});
                }
            }
        }
    }
    cout<<res<<endl;
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