#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=8;
    int ar[n]={1,3,2,5,1,1,2,3};
    int target=8;
    int i=0,j=0,sum=0,flag=1;
    while(i<n && j<n){
        while(sum+ar[j]<target){
            sum+=ar[j];
            j++;
        }
        if(sum+ar[j]==target){
            cout<<i<<" "<<j<<endl;
            flag=false;
            break;
        }
        else{
            sum-=ar[i];
            i++;    
        }
    }
    if(flag)
    cout<<"Not Found\n";
    return 0;
}