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
    MaxFlow(int _n) : n(_n), s(0), t(0), h(n, -1), d(n), cur(n) {
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
    T work(int s_, int t_) {
        s = s_;
        t = t_;
        return dinic();
    }
};

using M = MaxFlow<Edge<ll>, ll>;
void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> p(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        int now = i + 1;
        if (s[i] == 'p') {
            for (int j = 1; j <= now; j++) {
                while (!p[j].empty() && p[j].back() > now) p[j].pop_back();
            }
        } else if (s[i] == 's') {
            for (int j = now; j <= n; j++) {
                while (!p[j].empty() && p[j].back() > n - i) p[j].pop_back();
            }
        }
    }

    M f(n * 2 + 2, 0, n * 2 + 1);
    for (int i = 1; i <= n; i++) {
        if (p[i].empty()) {
            cout << "NO\n";
            return;
        }
        for (int j : p[i]) {
            f.addEdge(i, j + n, 1); 
        }
        f.addEdge(n + i, n * 2 + 1, 1);
        f.addEdge(0, i, 1);
    }

    int res = f.work(0, n * 2 + 1);
    if (res == n) cout << "YES\n";
    else cout << "NO\n";
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