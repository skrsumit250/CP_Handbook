#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=10,x=4,idx=0;
    int ar[n]={1,2,3,4,5,6,7,8,9,10};

    // Other version of binary search
    for(int i=n/2;i>=1;i/=2){
        while(idx+i<n && ar[idx+i]<=x)
        idx+=i,cout<<idx<<endl;
    }
    if(ar[idx]==x)
    cout<<"Found x at "<<idx<<"\n";
    else
    cout<<"Not Found\n";
    return 0;
}