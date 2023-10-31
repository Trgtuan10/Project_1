#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10001;

int n, m, s, t;
vector<int> neighbor[MAXN];
vector<vector<int>> c(MAXN, vector<int>(MAXN, 0));  // capacity
vector<vector<int>> f(MAXN, vector<int>(MAXN, 0));  // flow
vector<bool> vis;
int trace[10001];

void input_and_makeGraph() {
    cin >> n >> m;
    cin >> s >> t;

    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        neighbor[u].push_back(v);
        neighbor[v].push_back(u);
        c[u][v] = w;
        c[v][u] = 0;
    }
}

bool bfs(int u) { // search route to t
    vis.assign(n, false);
    vis[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == t) return true;
        for (auto &v : neighbor[x]) {
            if (c[x][v] - f[x][v] > 0 && !vis[v]) {
                q.push(v);
                trace[v] = x;
                vis[v] = true;
            }
        }
    }
    return false;
}

int increase_flow() {
    int min_flow = INT_MAX;     // find min remaining capacity
    int temp = t;
    while (temp != s) {
        int u = trace[temp];
        min_flow = min(min_flow, c[u][temp] - f[u][temp]);
        temp = u;
    }

    int u = t;
    while (u != s) {
        int v = trace[u];
        f[v][u] += min_flow;
        f[u][v] -= min_flow;
        u = v;
    }

    return min_flow;
}

int solve() {
    int max_flow = 0;
    while (bfs(s)) { // loop until there is no more augmenting flow route
        max_flow += increase_flow();
    }
    return max_flow;
}

int main() {
    // freopen("z.inp", "r", stdin);
    input_and_makeGraph();
    cout << solve();
    return 0;
}
