#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int n,sum;
vector<int>coin(100100);
vector<int>dp(100100,-1);
int rec(int x){
    if(x<0)
    return 0;
    if(x==0)
    return 1;
    if(dp[x]!=-1)
    return dp[x];

    int res=0;
    for(int i=0;i<n;i++){
        res+=rec(x-coin[i]);
    }
    return dp[x]=res;
}
int main(){
    ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    inputFile>>n>>sum;
    for(int i=0;i<n;i++){
        inputFile>>coin[i];
    }
    // DP using recusrsion and momoization
    cout<<rec(sum)<<endl;

    // DP using iteration
    vector<int>dpi(sum+1,0);
    dpi[0]=1;
    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(i-coin[j]>=0){
                dpi[i]+=dp[i-coin[j]];
            }
        }
    }
    cout<<dpi[sum]<<endl;
    return 0;
}