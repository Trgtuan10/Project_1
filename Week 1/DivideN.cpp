#include<bits/stdc++.h>

using namespace std; 

int main(){
    int n;
    cin >> n;
    int end = 999/n;    
    int start = 99/n;
    for(int i=start+1; i<=end; i++){
        cout << i*n << endl;
    }
    return 0;
}