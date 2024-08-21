# include <bits/stdc++.h>
using namespace std;

using i64 = long long;


template<class T>
struct MaxFlow {
    int n;
    vector<int> r, t, to, h, cur;
    vector<T> c;
    MaxFlow(int n, int m = 0) {
        init(n, m);
    }
    void init(int n, int m = 0) {
        this->n = n;
        r.assign(n, -1);
        h.assign(n, -1);
        cur.assign(n, 0);
        t.reserve(2 * m);
        to.reserve(2 * m);
        c.reserve(2 * m);
    }
    void addEdge(int u, int v, T cap) {
        t.push_back(r[u]), to.push_back(v), c.push_back(cap), r[u] = t.size() - 1;
        t.push_back(r[v]), to.push_back(u), c.push_back(0), r[v] = t.size() - 1;
    }
    bool bfs(int s, int e) {
        fill(h.begin(), h.end(), -1);
        queue<int> q;
        h[s] = 0;
        cur[s] = r[s];
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = r[u]; ~i; i = t[i]) {
                int v = to[i];
                T cap = c[i];
                if (cap > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    cur[v] = r[v];
                    if (v == e) {
                        return true;
                    }
                    q.push(v);
                }
            }
        }
        return false;
    }
    T dfs(int u, int e, T f) {
        if (u == e) {
            return f;
        }
        T r = f;
        for (int &i = cur[u]; ~i; i = t[i]) {
            int v = to[i];
            T cap = c[i];
            if (cap > 0 && h[v] == h[u] + 1) {
                T k = dfs(v, e, min(cap, r));
                if (k == 0) {
                    h[v] = -1;
                }
                c[i] -= k;
                c[i ^ 1] += k;
                r -= k;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    T flow(int s, int e) {
        T ans = 0;
        while (bfs(s, e)) {
            ans += dfs(s, e, std::numeric_limits<T>::max());
        }
        return ans;
    }

    std::vector<bool> minCut() {
        std::vector<bool> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = (h[i] != -1);
        }
        return c;
    }

    struct Edge {
        int from;
        int to;
        T cap;
        T flow;
        friend ostream &operator<<(ostream &cout, Edge u) {
            return cout << '{' << u.from << ", " << u.to << ", " << u.cap << ", " << u.flow << "}";
        }
    };
    vector<Edge> edges() {
        vector<Edge> a;
        for (int i = 0; i < t.size(); i += 2) {
            Edge x;
            x.from = to[i + 1];
            x.to = to[i];
            x.cap = c[i] + c[i + 1];
            x.flow = c[i + 1];
            a.push_back(x);
        }
        return a;
    }
};
const i64 inf = 1e18;
void solve () {
    int n, k;
    cin >> n >> k;
    int s = 0, t = n * 5;
    MaxFlow<i64> g(n * 5 + 3);
    int f = n * 5 + 1, e = f + 1;
    vector<i64> d(n * 5 + 10);
    while (k--) {
        int i;
        cin >> i;
        d[0] -= 1e9;
        d[i] += 1e9;
        g.addEdge(0, i, 0);
        d[i] -= 1e9;
        d[i + n] += 1e9;
        g.addEdge(i, i + n, 0);
        d[i] -= 1e9;
        d[i + n * 2] += 1e9;
        g.addEdge(i, i + n * 2, 0);
    }

    for (int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        d[x + n] -= w;
        d[i + n * 3] += w;
        g.addEdge(x + n, i + n * 3, 0);
        d[y + n] -= w;
        d[i + n * 3] += w;
        g.addEdge(y + n, i + n * 3, 0);
        g.addEdge(i + n * 3, t, w);
    }
    for (int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        d[x + n * 2] -= w;
        d[i + n * 4] += w;
        g.addEdge(x + n * 2, i + n * 4, 0);
        d[y + n * 2] -= w;
        d[i + n * 4] += w;
        g.addEdge(y + n * 2, i + n * 4, 0);
        g.addEdge(i + n * 4, t, w);
    }
    i64 tot = 0;
    for (int i = 0; i < n * 5 + 1; i += 1) {
        if (d[i] > 0) {
            g.addEdge(f, i, d[i]);
            tot += d[i];
        } else {
            g.addEdge(i, e, -d[i]);
        }
    }
    g.addEdge(t, s, inf);
    i64 p = g.flow(f, e);

    tot = g.c.end()[-1];
    g.c.end()[-1] = g.c.end()[-2] = 0;
    cout << tot + g.flow(s, t) << '\n';
}


signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	i64 _ = 1;
    cin >> _;
	while (_ --) {
        solve ();
	}
	return 0;
}