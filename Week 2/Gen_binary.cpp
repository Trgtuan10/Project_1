#include<bits/stdc++.h>

using namespace std; 

int n;
int a[21] = {0};

void Ghinhan(int n, int a[]){
    for(int i=1; i<=n; i++){
        cout << a[i];
    }
    cout << endl;
}

void Try(int i, int n){
    for(int k=0; k<=1; k++){
        a[i] = k;
        if(i == n) Ghinhan(n,a);
        else Try(i+1, n);
    }
}

int main(){
    cin >> n;
    Try(1,n);
    return 0;
}