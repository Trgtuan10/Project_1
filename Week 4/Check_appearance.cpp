//C++ 
#include <bits/stdc++.h> 

using namespace std; 

int main() 
{ 
    int n;
    cin >> n;
    set<int> lam; 
    int a;
    for (int i=0; i<n; i++){
        cin >>a; 
        if(lam.find(a) != lam.end()) cout << "1" << '\n';
        else cout << "0" << '\n';
        lam.insert(a);
    }
    return 0;
}
