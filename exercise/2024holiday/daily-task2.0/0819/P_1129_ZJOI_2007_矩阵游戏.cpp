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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    M mf(n * 2 + 2, n * 2, n * 2 + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j]) mf.addEdge(i, j + n, 1);
        }
    }
    for (int i = 0; i < n; i++) {
        mf.addEdge(n * 2, i, 1);
        mf.addEdge(i + n, n * 2 + 1, 1);
    }
    ll ans = mf.dinic();
    if (ans == n) cout << "Yes\n";
    else cout << "No\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}