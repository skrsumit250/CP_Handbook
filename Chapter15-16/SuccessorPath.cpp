#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int succ[100100];
int dp[32][100100];
int rec(int x,int k,vector<int>&bits){
    if(k==bits.size()-1)
    return dp[bits[k]][x];

    return dp[bits[k]][rec(x,k+1,bits)];
}
int main(){
    ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    inputFile>>n;
    for(int i=1;i<=n;i++){
        inputFile>>succ[i];
    }
    for(int i=1;i<=n;i++){
        dp[0][i]=succ[i];
    }
    for(int i=1;i<32;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    vector<int>bits;
    int x=4,k=11;
    for(int i=0;k>0;i++){
        if(k&1)
        bits.push_back(i);

        k=k/2;
    }
    cout<<rec(x,0,bits);
    return 0;
}