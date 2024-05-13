#include<bits/stdc++.h>
using namespace std;
int GCD(int a,int b){
    if(b==0)
    return a;
    return GCD(b,a%b);
}
int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<GCD(24,36)<<endl;
    return 0;
}