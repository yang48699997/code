using ll = long long;
template<class T>
struct Edge {
    int to;
    T cap;
    T cost;
    Edge(int to_, T cap_, T cost_) : to(to_), cap(cap_), cost(cost_) {}
};

template<class E, class T>
struct MinCostFlow {
    int n, s, t;
    vector<E> e;
    vector<vector<int>> g;
    vector<T> h, dis;
    vector<int> pre;
    MinCostFlow() {}
    MinCostFlow(int n_, int s_, int t_) : n(n_), s(s_), t(t_), {
        e.clear();
        g.assign(n, {});
    }
    void addEdge(int u, int v, T cap, T cost) {
        g[u].push_back(e.size());
        e.emplace_back(v, cap, cost);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -cost);
    }
    bool dijkstra() {
        dis.assign(n, numeric_limits<T>::max());
        pre.assign(n, -1);
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            T d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (dis[u] != d) {
                continue;
            }
            for (int i : g[u]) {
                int v = e[i].to;
                T cap = e[i].cap;
                T cost = e[i].cost;
                if (cap > 0 && dis[v] > d + h[u] - h[v] + cost) {
                    dis[v] = d + h[u] - h[v] + cost;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != numeric_limits<T>::max();
    }
    pair<T, T> flow() {
        T flow = 0;
        T cost = 0;
        h.assign(n, 0);
        while (dijkstra()) {
            for (int i = 0; i < n; ++i) {
                h[i] += dis[i];
            }
            T aug = numeric_limits<int>::max();
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                aug = min(aug, e[pre[i]].cap);
            }
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                e[pre[i]].cap -= aug;
                e[pre[i] ^ 1].cap += aug;
            }
            flow += aug;
            cost += aug * h[t];
        }
        return make_pair(flow, cost);
    }
};

using M = MinCostFlow<Edge<ll>, ll>;