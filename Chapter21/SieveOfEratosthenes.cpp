#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=100100;
    int sieve[n]={0};
    for(int i=2;i<n;i++){
        if(!sieve[i]){
            for(int j=2*i;j<n;j+=i){
                sieve[j]=1;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(!sieve[i])
        cout<<i<<" ";
    }
    return 0;
}