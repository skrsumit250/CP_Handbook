#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=8;
    int ar[n]={2,1,4,5,3,4,1,2};
    deque<int>dq;
    for(int i=0;i<4;i++){
        while(!dq.empty() && dq.back()>ar[i]){
            dq.pop_back();
        }
        dq.push_back(ar[i]);
    }
    cout<<dq.front()<<" ";
    for(int i=4,j=0;i<n;i++,j++){
        while(!dq.empty() && dq.back()>ar[i]){
            dq.pop_back();
        }
        dq.push_back(ar[i]);
        if(dq.front()==ar[j]){
            dq.pop_front();
        }
        cout<<dq.front()<<" ";
    }
    return 0;
}