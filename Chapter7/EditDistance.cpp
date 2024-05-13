#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a="LOVE",b="MOVIE";
    int n=4,m=5;
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp[i-1][j-1]+(a[i-1]!=b[j-1]),1+min(dp[i-1][j],dp[i][j-1]));
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}