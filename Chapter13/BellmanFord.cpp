#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,src;
    cin>>n>>m>>src;
    vector<pair<ll,pair<ll,ll>>>edge;
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edge.push_back({a,{b,c}});
        edge.push_back({b,{a,c}});
    }
    vector<ll>dis(n+1,1e9);
    dis[src]=0;
    for(ll i=2;i<n;i++){
        for(auto x:edge){
            dis[x.first]=min(dis[x.first],dis[x.second.first]+x.second.second);
        }
    }
    for(ll i=1;i<=n;i++)
    cout<<src<<"-> "<<i<<" = "<<dis[i]<<"\n";
    cout<<endl;
    return 0;
}