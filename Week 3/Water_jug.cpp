#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int a, b, c;
bool check[901][901];
int t[901][901];

// Function to perform BFS
int bfs(int x, int y, int c) {
    queue<pii> q;
    q.push(make_pair(x, y));
    t[x][y] = 0; // Initialize the time to 0 for the initial state
    check[x][y] = true;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        x = cur.first;
        y = cur.second;

        if (x == c || y == c) {
            return t[x][y]; // Found a solution, return the time it took
        }

        // Fill the jug x to its full capacity
        if (!check[a][y]) {
            q.push(make_pair(a, y));
            t[a][y] = t[x][y] + 1;
            check[a][y] = true;
        }

        // Fill the jug y to its full capacity
        if (!check[x][b]) {
            q.push(make_pair(x, b));
            t[x][b] = t[x][y] + 1;
            check[x][b] = true;
        }

        // Empty jug x
        if (!check[0][y]) {
            q.push(make_pair(0, y));
            t[0][y] = t[x][y] + 1;
            check[0][y] = true;
        }

        // Empty jug y
        if (!check[x][0]) {
            q.push(make_pair(x, 0));
            t[x][0] = t[x][y] + 1;
            check[x][0] = true;
        }

        // Pour water from x to y
        int pour = min(x, b - y); // Amount that can be poured from x to y
        if (!check[x - pour][y + pour]) {
            q.push(make_pair(x - pour, y + pour));
            t[x - pour][y + pour] = t[x][y] + 1;
            check[x - pour][y + pour] = true;
        }

        // Pour water from y to x
        pour = min(y, a - x); // Amount that can be poured from y to x
        if (!check[x + pour][y - pour]) {
            q.push(make_pair(x + pour, y - pour));
            t[x + pour][y - pour] = t[x][y] + 1;
            check[x + pour][y - pour] = true;
        }
    }

    return -1; // No solution found
}

int main() {
    cin >> a >> b >> c;
    cout << bfs(0, 0, c);
    return 0;
}
