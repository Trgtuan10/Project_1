#include<iostream>

using namespace std;

int n,N,M, count, a[1000];

void Ghinhan(int M){
    count ++;
    for (int i=1; i<n; i++){
        cout<< a[i] << " ";
    }
    cout << N-M <<" "<< endl;
}

void Try(int k){
    int u = N - M - n + k;
    for (int i=1; i<=u; i++){
        M += i;
        a[k] = i;
        if(k == n-1) Ghinhan(M);
        else Try(k+1);
        M -= a[k];
    }
}

int main(){
    cin>> n >> N;
    Try(1);
    return 0;
}