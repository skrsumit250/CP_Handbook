#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,x;
int succ[100100];
int main(){
    ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    inputFile>>n>>x;
    for(int i=1;i<=n;i++){
        inputFile>>succ[i];
    }
    int a=succ[x],b=succ[succ[x]];
    while(a!=b){
        a=succ[a];
        b=succ[succ[b]];
    }
    int l=1;
    b=succ[a];
    while(a!=b){
        b=succ[b];
        l++;
    }
    cout<<"First node at cycle start = "<<b<<endl;
    cout<<"Length of cycle = "<<l<<endl;
    return 0;
}