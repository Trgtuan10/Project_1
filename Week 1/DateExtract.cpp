#include<bits/stdc++.h>

using namespace std;

string s;

void solve(){
    int k = s.length();
    if(k != 10) {
        cout << "INCORRECT";
        return;
    }; 
    string year = s.substr(0,4);
    char x1 = s[4];
    string month = s.substr(5,2);
    char x2 = s[7];
    string day = s.substr(8,2);

    if(x1 == '-' && x2 == '-' && stoi(month) <= 12 && stoi(day) <=31){
        cout << stoi(year) << " " << stoi(month) << " " << stoi(day);
    }
    else cout << "INCORRECT";
    
}

int main(){
    getline(cin,s);
    solve();
    return 0;
}