#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=8,k=3;
    int price[k][n]={
        {6,9,5,2,8,9,1,6},
        {8,2,6,2,7,5,7,2},
        {5,3,9,7,3,5,1,4}
    };
    int total[1<<k][n];
    for(int i=0;i<k;i++){
        total[1<<i][0]=price[i][0];
        cout<<(1<<i)<<" "<<0<<" "<<price[i][0]<<endl;
    }
    for(int j=1;j<n;j++){
        for(int i=0;i<(1<<k);i++){
            total[i][j]=total[i][j-1];
            for(int x=0;x<k;x++){
                if(i&(1<<x)){
                    total[i][j]=min(total[i][j],total[i^(1<<x)][j-1]+price[x][j]);
                    cout<<i<<" "<<(1<<x)<<" "<<total[i][j]<<endl;
                }
                
            }
        }
    }
    return 0;
}