#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>adj[100100];
vector<bool>vis(100100,false);
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
    int dis[n+1]={0};
    dis[1]=0;
    queue<int>q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto x:adj[curr]){
            if(!vis[x]){
                q.push(x);
                vis[x]=true;
                dis[x]=dis[curr]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}
// 6 6
// 1 2
// 1 4
// 2 3
// 2 5
// 3 6
// 5 6