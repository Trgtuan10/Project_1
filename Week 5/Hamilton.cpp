#include<bits/stdc++.h>

using namespace std; 

const int MAXN = 1e5+1;

int n, m, t;
int c;
vector<int> edge[MAXN];
bool check[MAXN];

int res = 0;

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

    check[1] = true;
}

void DFS(int k){
    for(auto &x : edge[k]){
        if(check[x] == false){
            check[x] = true;
            c++; 

            if(c == n){
                for(auto &y : edge[x]) if(y == 1){
                    res = 1;
                    break;
                }
            }
            else{
                DFS(x);
            }

            check[x] = false; 
            c--;
        }
    }
}

int main(){
    cin >> t; 
    while(t--){
        c = 1;
        input();
        DFS(1);
        cout << res << endl; 
    }
    return 0;
}