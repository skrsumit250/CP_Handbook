#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=4;
    int w[n]={1,3,3,5};
    int sum=12;
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j-w[i-1]>=0)
            dp[i][j]=dp[i][j] | (dp[i-1][j-w[i-1]]|dp[i-1][j]);
            else
            dp[i][j]=dp[i][j] | dp[i-1][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}