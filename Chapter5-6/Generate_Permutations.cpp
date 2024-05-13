#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>v(100100);
vector<int>subset;
vector<bool>vis(100100,false);
void generate_permutaion(){
    if(subset.size()==n){
        for(auto x:subset)
        cout<<x<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=true;
            subset.push_back(v[i]);
            generate_permutaion();
            subset.pop_back();
            vis[i]=false;
        }
    }
}
int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        p[i]=v[i];
    }
    // Recursive method to generate Permutation
    generate_permutaion();

    cout<<"Use built-in Function\n";
    do{
        for(int i=0;i<n;i++)
        cout<<p[i]<<" ";
        cout<<"\n";
    }while(next_permutation(p.begin(),p.end()));
    return 0;
}