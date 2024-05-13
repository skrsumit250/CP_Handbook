#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=4;
    int v[n]={2,2,2,2};
    int dp[n];
    int res=1;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        res=max(res,dp[i]);
    }
    cout<<res<<endl;

    // More optimize code
    vector<int>p,len(n);
    p.push_back(v[0]);
    for(int i=1;i<n;i++){
        if(v[i]>p.back())
        p.push_back(v[i]);
        else{
            auto it=lower_bound(p.begin(),p.end(),v[i]);
            p[it-p.begin()]=v[i];
        }
    }
    cout<<p.size()<<endl;
    return 0;
}