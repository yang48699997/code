#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct Edge {
    int to, next;
    T cap;
    Edge(int _to, int _next, T _cap) : to(_to), next(_next), cap(_cap) {}
};

template<class E, class T>
struct MaxFlow {
    int n, s, t;
    vector<E> e;
    vector<int> h, d, cur;
    MaxFlow() {}
    MaxFlow(int _n, int _s, int _t) : n(_n), s(_s), t(_t), h(n, -1), d(n), cur(n) {
        e.clear();
    }
    void addEdge(int u, int v, T cap) {
        e.emplace_back(v, h[u], cap);
        h[u] = e.size() - 1;
        e.emplace_back(u, h[v], 0);
        h[v] = e.size() - 1;
    }
    bool bfs() {
        d.assign(n, 0);
        queue<int> q;
        q.push(s);
        d[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = h[u]; i != -1; i = e[i].next) {
                int v = e[i].to;
                if (!d[v] && e[i].cap) {
                    d[v] = d[u] + 1;
                    q.push(v);
                    if (v == t) return true;
                }
            }
        }
        return false;
    }
    T dfs(int u, T mf) {
        if (u == t) return mf;
        T sum = 0;
        for (int &i = cur[u]; i != -1; i = e[i].next) {
            int v = e[i].to;
            if (d[v] == d[u] + 1 && e[i].cap) {
                T f = dfs(v, min(mf, e[i].cap));
                e[i].cap -= f;
                e[i ^ 1].cap += f;
                mf -= f;
                sum += f;
                if (mf == 0) break;
            }
        }
        if (sum == 0) d[u] = 0;
        return sum;
    }
    T dinic() {
        T flow = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) cur[i] = h[i];
            flow += dfs(s, numeric_limits<T>::max());
        }
        return flow;
    }
};

using M = MaxFlow<Edge<ll>, ll>;

int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    int sx, sy;
    cin >> sx >> sy;
    sx--;
    sy--;
    int tx, ty;
    vector<vector<int>> block(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#' || g[i][j] == '1') block[i][j] = 1;
            else if (g[i][j] == '.') {
                tx = i;
                ty = j;
            }
        }
    }

    vector<vector<int>> v(n, vector<int> (m));
    queue<array<int, 2>> q;
    q.push({x, y});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (v[p[0]][p[1]]) continue;
        v[p[0]][p[1]] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = p[0] + dir[i][0];
            int ny = p[1] + dir[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || block[nx][ny]) continue;
            q.push({nx, ny});
        }
    }

    if (!v[tx][ty] || !v[sx][sy]) {
        cout << "No\n";
        return;
    }

    M f(n * m, m * sx + sy, m * tx + ty);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < )
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}