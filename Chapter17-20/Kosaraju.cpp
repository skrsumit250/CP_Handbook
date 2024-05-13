#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>adj[100100];
vector<int>rev[100100];
vector<bool>vis(100100,false);
stack<int>st;
void DFS(int node){
    vis[node]=true;
    for(auto x:adj[node]){
        if(!vis[x])
        DFS(x);
    }
    st.push(node);
}
void SCG(int node,vector<int>&p){
    vis[node]=true;
    for(auto x:rev[node]){
        if(!vis[x]){
            SCG(x,p);
        } 
    }
    p.push_back(node); 
}
int main(){
    ifstream inputFile("input.txt");
    inputFile>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        inputFile>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])
        DFS(i);
    }
    for(int i=1;i<=n;i++){
        vis[i]=false;
    }
    vector<vector<int>>res;
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        if(!vis[curr]){
            vector<int>p;
            SCG(curr,p);
            res.push_back(p);
        }
    }
    for(auto x:res){
        for(auto t:x)
        cout<<t<<" ";
        cout<<endl;
    }
    return 0;
}