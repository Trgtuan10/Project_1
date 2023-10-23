#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

int n, m;
int res = 0;
int parent[MAXN];

struct edge {
    int u, v;
    int w;
};

vector<edge> v;

bool cmp(edge &x, edge &y) {
    return x.w < y.w;
}

void input() {
    scanf("%d %d", &n, &m);
    int a, b, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        v.push_back({a, b, w});
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 1; i <= n; i++) parent[i] = i; // make set
}

int find_set(int u) {
    if (u != parent[u]) {
        parent[u] = find_set(parent[u]); 
    }
    return parent[u];
}

int Kruskal() {
    for (int i = 0; i < m; i++) {
        int x = find_set(v[i].u);
        int y = find_set(v[i].v);
        if (x != y) {
            res += v[i].w;
            parent[x] = y;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    input();
    Kruskal();
    printf("%d\n", res); 
    return 0;
}
