#include <bits/stdc++.h> 

using namespace std; 

int n;
vector<int> v;

int sum(vector<int> &v){
    int sum = 0;
    for(auto &u : v){
        sum+=u;
    }
    return sum;
}

int find_max(vector<int> &v, int start, int end){
    int max = v[start];
    for(int i=start; i<=end; i++){
        if(max < v[i]) max= v[i];
    }
    return max;
}

int find_min(vector<int> &v){
    int min = v[0];
    for(int i=0; i<v.size(); i++){
        if(min > v[i]) min= v[i];
    }
    return min;
}

void input(){
    cin >> n;
    int x;
    for(int i=1; i<=n; i++){
        cin >> x;
        v.push_back(x);
    }
}

int main(){
    input();
    string cmd;
    while(cin >> cmd){
        if(cmd == "*") continue;
        if(cmd == "find-max"){
            cout << find_max(v,0,v.size()-1);
        }
        if(cmd == "find-min"){
            cout << find_min(v);
        }
        if(cmd == "sum"){
            cout << sum(v);
        }
        if(cmd == "find-max-segment"){
            int a,b;
            cin >> a >> b;
            cout << find_max(v,a-1,b-1);
        }
        if(cmd == "***") break;
    }
    return 0;
    
}