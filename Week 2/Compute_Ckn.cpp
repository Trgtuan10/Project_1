#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int c[1000][1000];

int n, k;

int C(int k, int n){
    if(k == 0 || k == n) return 1;
    if(c[k][n] != 0) return c[k][n];
    c[k][n]  = (C(k - 1, n - 1) + C(k, n - 1)) % MOD;
}

int main(){
    cin >> k >> n; 
    cout << C(k, n);
    return 0;
}