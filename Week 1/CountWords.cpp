#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int count_all = 0;
    while (getline(cin, s)) {
        int count = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            while (i < n && (s[i] == ' ' || s[i] == '\t')) {
                i++;
            }
            
            if (i < n) {  
                count++; 
                while (i < n && s[i] != ' ' && s[i] != '\t') {
                    i++;
                }
            }
        }
        count_all += count;    
    }
    cout << count_all;
    return 0;
}
