#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n=84;
    // Factors
    vector<int>factor;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            factor.push_back(i);
            if(i!=(n/i))
            factor.push_back(n/i);
        }
    }
    sort(factor.begin(),factor.end());
    // Numbers of factor
    cout<<factor.size()<<endl;

    for(auto x:factor){
        cout<<x<<" ";
    }
    cout<<endl;

    int prime_factor[3][2]={
        {2,2},
        {3,1},
        {7,1}
    };
    // Numbers of factor
    int count=1;
    for(int i=0;i<3;i++){
        count*=(prime_factor[i][1]+1);
    }
    cout<<count<<endl;
    // Sum of factors
    count=1;
    for(int i=0;i<3;i++){
        int p=pow(prime_factor[i][0],prime_factor[i][1]+1)-1;
        p=p/(prime_factor[i][0]-1);
        count*=p;
    }
    cout<<count<<endl;

    //Density of primes
    cout<<int(n/log(n))<<endl;

    // Prime Factors;
    map<int,int>pf;
    n=84;
    int m=n;
    for(int i=2;i<=m;i++){
        while(n%i==0){
            pf[i]++;
            n/=i;
        }
    }
    for(auto x:pf)
    cout<<x.first<<" "<<x.second<<endl;
    return 0;
}