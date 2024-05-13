#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=8;
    int ar[n]={1,4,5,6,7,9,9,10};
    int target=12;
    int i=0,j=n-1,sum=0,flag=1;
    while(i<=j){
        sum=ar[i]+ar[j];
        if(sum==target){
            cout<<"Found\n";
            cout<<i<<" "<<j<<endl;
            flag=0;
            break;
        }
        else if(sum<target)
        i++;
        else if(sum>target)
        j--;
    }
    if(flag)
    cout<<"Not Found\n";
    return 0;
}