#include<bits/stdc++.h>

using namespace std; 

int n,m, p[201];

void count_base(){
    p[0] = 1;
    for (int i=1; i<=200; i++){
        p[i] = (256*p[i-1]) % m;
    }
}

void solve(string s){
        int l = s.length(); 
        int res = 0; 
        for(int i=0; i<l; i++){
            res += (s[i] * p[(l-i-1)%m]) % m;
        } 
        cout << res % m << '\n';
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m; 
    count_base();
    string s; 
    for(int i=0; i<n; i++){
        cin >> s; 
        solve(s);
    }
    return 0;
}