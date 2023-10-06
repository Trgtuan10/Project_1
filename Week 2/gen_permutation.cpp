#include<bits/stdc++.h>
using namespace std;

const int MAX=1000; 

int n; 
int a[MAX];
bool check[MAX] = {false};

void Ghinhan(int n, int a[]){
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int k, int n){
    for(int i=1; i<=n; i++){
        // cout << i;
        if(check[i] == false){
            a[k] = i; 
            check[i] = true;
            if(k == n) Ghinhan(n, a);
            else Try(k+1, n);
            check[i] = false;
        }
    }
}

int main(){
    cin >> n;
    Try(1,n);
    return 0;
}