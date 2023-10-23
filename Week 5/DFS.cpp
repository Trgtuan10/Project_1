#include<bits/stdc++.h>

using namespace std; 

const int MAXN = 1e5+1;

int n, m;
vector<int> edge[MAXN];
bool check[MAXN];

void input(){
    cin >> n >> m;
    int a,b; 
    while(m--){
        cin >> a >> b; 
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        sort(edge[i].begin(), edge[i].end());
    }
}

void DFS(int k){
    cout << k << " ";
    check[k] = true;
    for(auto &x : edge[k]){
        if(check[x] == false) DFS(x);
    }
}

int main(){
    input();
    for(int i=1; i<=n ; i++)  if(check[i] == false) DFS(i);
    return 0;
}