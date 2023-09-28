#include<bits/stdc++.h>

using namespace std; 

int main(){
    string text;
    while(getline(cin, text)){
        for(char &c: text) c=toupper(c);
        cout << text;
        cout << endl;
    }
    return 0;
}