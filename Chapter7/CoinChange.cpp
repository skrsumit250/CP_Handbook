#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int n,sum;
vector<int>coin(100100);
vector<int>dp(100100,-1);
int rec(int x){
    if(x<0)
    return INF;
    if(x==0)
    return 0;
    if(dp[x]!=-1)
    return dp[x];

    int res=INF;
    for(int i=0;i<n;i++){
        res=min(res,1+rec(x-coin[i]));
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

    // DP using iteration and also the required coins for optimum solution
    vector<int>dpi(sum+1,INF),coins(sum+1,0);
    dpi[0]=0;
    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(i-coin[j]>=0 && dpi[i-coin[j]]+1<dpi[i]){
                dpi[i]=1+dpi[i-coin[j]];
                coins[i]=coin[j];
            }
        }
    }
    cout<<dpi[sum]<<endl;
    while(sum>0){
        cout<<coins[sum]<<" ";
        sum-=coins[sum];
    }
    return 0;
}