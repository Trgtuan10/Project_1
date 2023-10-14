#include<bits/stdc++.h>

using namespace std;

string s;
stack<char> st;

int solve(string s){
    int k = s.length();
    // cout << k;

    for(int i=0; i<k; i++){
        // cout << s[i] << endl;
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else{
            if((s[i] == ')' || s[i] == ']' || s[i] == '}') && st.empty()) return 0;
            else{
                if((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')) st.pop();
                else return 0;
            }
        }
    }

    if (!st.empty()) return 0;
    return 1;
}

int main(){
    // freopen("test.inp", "w", stdin);
    // freopen("test.out", "r", stdout);

    cin >> s;
    cout << solve(s);
    return 0;
}
