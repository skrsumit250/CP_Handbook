#include<bits/stdc++.h>
using namespace std;
int n;
vector<bool>col(100100,false);
vector<bool>diag1(100100,false);
vector<bool>diag2(100100,false);
int count_ways(int row=0){
    if(row==n){
        return 1;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!col[i] && !diag1[row+i] && !diag2[n-row+i-1]){
            col[i]=diag1[row+i]=diag2[n-row+i-1]=true;
            count+=count_ways(row+1);
            col[i]=diag1[row+i]=diag2[n-row+i-1]=false;
        }
    }
    return count;
}

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int count=0;
    cout<<count_ways()<<"\n";
    return 0;
}