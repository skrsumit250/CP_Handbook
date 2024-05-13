#include<bits/stdc++.h>
using namespace std;
vector<int>v(100100);
vector<int>subset;
void generate_subset(int i){
    if(i<0){
        if(subset.size()==0){
            cout<<"NULL subset\n";
            return;
        }
        for(auto x:subset)
        cout<<x<<" ";
        cout<<"\n";
        return;
    }
    subset.push_back(v[i]);
    generate_subset(i-1);
    subset.pop_back();
    generate_subset(i-1);
}
int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // Recursive method to generate subset
    generate_subset(n-1);

    // Bit representatio of number to generate subset

    for(int i=0;i<(1<<n);i++){
        bool empty=true;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                empty=false;
                cout<<v[j]<<" ";
            }
        }
        if(empty)
        cout<<"NULL subset";
        cout<<"\n";
    }
    return 0;
}