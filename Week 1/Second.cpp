#include<bits/stdc++.h>

using namespace std;

string s;

void solve(){
    int k = s.length();
    if(k != 8) {
        cout << "INCORRECT";
        return;
    }; 
    string hour = s.substr(0,2);
    char x1 = s[2];
    string mi = s.substr(3,2);
    char x2 = s[5];
    string se = s.substr(6,2);

    if(x1 == ':' && x2 == ':' && stoi(hour) <= 23 && stoi(mi) <=59 && stoi(se) <= 59){
        cout << stoi(hour) * 3600 + stoi(mi) * 60 + stoi(se);
    }
    else cout << "INCORRECT";
    
}

int main(){
    getline(cin,s);
    solve();
    return 0;
}