#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=5,m=5;
    int ar[n][m]={
        {3,7,9,2,7},
        {9,8,3,5,5},
        {1,7,9,8,5},
        {3,8,6,4,10},
        {6,3,9,7,8}
    };
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=ar[i-1][j-1]+max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}