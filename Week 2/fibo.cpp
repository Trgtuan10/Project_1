#include<bits/stdc++.h>

using namespace std;

int n;

int a[22];

int fibo(int n){
    if(n == 0 ) return 0; 
    if( n == 1) return 1;
    else {
        a[n] = fibo(n-1) + fibo(n-2);
        return a[n];
    }

}

int main(){
    cin >> n;
    cout << fibo(n-1);
    return 0;
}