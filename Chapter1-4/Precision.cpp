#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    float a=2.3456;// 4bytes
    double b=3.1434545667987;
    printf("%.20f %.20f \n",a,b);
    // OR
    cout<<fixed<<setprecision(5);
    cout<<a<<"\n"<<b;
    return 0;
}