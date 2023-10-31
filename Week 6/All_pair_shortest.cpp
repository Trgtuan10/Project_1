#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; 

const int MAXN = 1e5+5; 

int n,m,s,t; 
vector<pii> adj_edge[MAXN];
vector<bool> vis;
vector<int> dis;

int input(){
    cin >> n >> m;

    int u,v,w;
    while(m--){
        cin >> u >> v >> w; 
        adj_edge[u].push_back(make_pair(w,v));
    }  
}

void Dijkstra(int s){ 
    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    dis.assign(n+1, INT_MAX); 
    vis.assign(n+1, false);

    dis[s] = 0; 
    pq.push(make_pair(0, s));

    int count = 1;

    while(!pq.empty() || count < n){
        int u = pq.top().second;
        int dist = pq.top().first; 
        pq.pop(); 

        if(vis[u]) continue; 
        vis[u] = true; 
        count++;

        for(auto x: adj_edge[u]){
            int v = x.second;
            int wei = x.first;

            if(vis[v]) continue;

            if(dis[u] + wei < dis[v]){
                dis[v] = dis[u] + wei;
                pq.push(make_pair(dis[v], v));
            }
        }
    }

    for(int i=1; i<= n; i++) cout << dis[i] << " ";
    cout << endl; 
}



int main(){
    input();
    for(int i=1; i<=n; i++){
        Dijkstra(i); 
    }
    return 0;
}
