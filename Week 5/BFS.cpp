#include<bits/stdc++.h>
using namespace std; 

const int MAXN = 1e5+1;
int n, m; 
vector<int> edge[MAXN];
queue<int> q;


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

void BFS(int k){
    q.push(k);
    check[k] = true; 
    int u;
    while(!q.empty()){
        u = q.front();
        cout << u << " ";
        q.pop();
        for(auto &x : edge[u]){
            if(check[x] == false){
                check[x] = true; 
                q.push(x);
            }
        }
    }
}

int main(){
    input();
    for(int i=1; i<=n; i++){
        if(check[i] == false) BFS(i);
    }
    return 0;
}