#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int x=14,k=3,y=78;
    // ~x=-x-1;
    cout<<~x<<" "<<-x-1<<endl;

    // x<<k ::  x=x*pow(2,k)
    cout<<(x<<k)<<" "<<x*pow(2,k)<<endl;

    // x>>k :: x=x/pow(2,k)
    cout<<(x>>k)<<" "<<x/int(pow(2,k))<<endl;

    // Print Binary Form
    for(int i=31;i>=0;i--){
        if(x&(1<<i))
        cout<<"1";
        else
        cout<<"0";
    }
    cout<<"\n";

    // set kth bit to 1
    cout<<(x|(1<<k))<<endl;

    // set kth bit to 0
    cout<<(x&(~(1<<k)))<<endl;

    // invert the kth bit
    cout<<(x^(1<<k))<<endl;

    // Set rightmost bit to 0
    cout<<(x&(x-1))<<endl;

    // Set all bits to 0 except the rightmost bit
    cout<<(x&(-x))<<endl;

    // x is a power of two if x&(x-1)=0
    cout<<(x&(x-1))<<endl;
    return 0;
}