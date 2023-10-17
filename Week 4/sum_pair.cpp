#include<bits/stdc++.h>

using namespace std; 


int main(){
    int n,m; 
    unordered_set<int> v; 
    int count = 0;
    cin >> n >> m; 

    while(n--){
        int x;
        cin >> x;
        int key = m-x; 
        if(v.find(key) != v.end()) count++;
        v.insert(x);
    }
    cout << count;
    // cout << solve(n,m,v);
    return 0;
}
