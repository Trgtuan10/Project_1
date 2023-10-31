#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; 

const int MAXN = 1e5+5; 

int n,m,s,t; 
bool vis[MAXN];
int best[MAXN]; 
vector<pii> adj_edge[MAXN];
vector<int> dis; 
priority_queue<pii, vector<pii>, greater<pii>> pq; 

int input(){
    cin >> n >> m;
    
    dis.assign(n+1, INT_MAX); 

    int u,v,w;
    while(m--){
        cin >> u >> v >> w; 
        adj_edge[u].push_back(make_pair(w,v));
    }
    cin >> s >> t; 

    dis[s] = 0; 
    pq.push(make_pair(0, s));
}

int Dijkstra(int s, int t){ 
    while(!pq.empty()){
        int u = pq.top().second;
        int dist = pq.top().first; 
        pq.pop(); 

        if(vis[u]) continue; 
        vis[u] = true; 

        if(u == t) return dis[u]; 

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
    return -1; 
}

int main(){
    input();
    cout << Dijkstra(s, t); 
}
