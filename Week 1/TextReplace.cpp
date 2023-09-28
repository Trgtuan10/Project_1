#include<bits/stdc++.h>

using namespace std;

string text;
string P1;
string P2;


int main(){

    getline(cin, P1);
    getline(cin, P2);
    getline(cin, text);
    
    int k = text.length();
    int l = P1.length();

    int i=0;
    int t=0;
    while(i<k){
        string temp = text.substr(i, l);
        if(temp != P1){
            cout << text[i];
            i++;
        }
        else{
            cout << P2;
            i = i + l;
        }
    }
    return 0;
}