#include<bits/stdc++.h>
using namespace std;
// Policy-based data structures
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    multiset<int>s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    // Erase all instance of 5
    s.erase(5);

    cout<<s.count(5)<<"\n"; // 0

    s.insert(5);
    s.insert(5);
    s.insert(5);
    // Erase only one instance of 5
    s.erase(s.find(5));
    cout<<s.count(5)<<"\n"; // 2



    indexed_set idx_set;
    idx_set.insert(2);
    idx_set.insert(3);
    idx_set.insert(7);
    idx_set.insert(9);

    //The function find_by_order returns an iterator to the element at a given position
    auto val=idx_set.find_by_order(2);
    cout<<*val<<"\n"; // 7
    //the function order_of_key returns the position of a given element
    cout<<idx_set.order_of_key(7)<<"\n"; //2
    
    return 0;
}