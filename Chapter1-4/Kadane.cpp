#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n=8,best=0;
    int ar[n]={-1,2,4,-3,5,2,-5,2};

    // Checking sum for subarray O(n^2)
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=ar[j];
            best=max(best,sum);
        }     
    }
    cout<<best<<"\n";

    // Kadane's Algorithm to find maximum sum of the subarray
    int sum=0;
    best=0;
    for(int i=0;i<n;i++){
        sum=max(sum+ar[i],ar[i]);
        best=max(best,sum);
        cout<<sum<<" "<<best<<endl;
    }
    cout<<best<<"\n";
    return 0;
}