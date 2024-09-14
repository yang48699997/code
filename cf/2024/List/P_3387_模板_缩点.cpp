#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct Tarjan {
    int tot, top, cnt;
    int n;
    vector<int> dfn, low, stk, instk, scc, siz;
    vector<vector<int>> e;
    Tarjan(int n_) : n(n_), tot(0), top(0), cnt(0), dfn(n_ + 1), low(n_ + 1), stk(n_ + 1), instk(n_ + 1), scc(n_ + 1), siz(n_ + 1), e(n_ + 1) {} 
    void addEdge(int u, int v) {
        e[u].push_back(v);
    }
    void init() {
        tot = top = cnt = 0;
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        instk.assign(n + 1, 0);
        siz.assign(n + 1, 0);
    }
    void tarjan(int x) {
        dfn[x] = low[x] = ++tot;
        stk[top++] = x;
        instk[x] = 1;
        for (int nxt : e[x]) {
            if (!dfn[nxt]) {
                tarjan(nxt);
                low[x] = min(low[x], low[nxt]);
            } else if (instk[nxt]) {
                low[x] = min(low[x], dfn[nxt]);
            }
        }
        if (dfn[x] == low[x]) {
            cnt++;
            int y = 0;
            while (y != x) {
                y = stk[--top];
                instk[y] = 0;
                scc[y] = cnt;
                siz[cnt]++;
            }
        }
        return;
    }
    void work() {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) tarjan(i);
        }
        return;
    }
    
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Tarjan tj(n);
    vector<pair<int, int>> p;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        tj.addEdge(x, y);
        p.emplace_back(x, y);
    }
    tj.work();
    vector<int> sum(n + 1);
    vector<int> dp(n + 1);
    vector<int> deg(n + 1);
    vector<vector<int>> e(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[tj.scc[i]] += a[i - 1];
        for (int nxt : tj.e[i]) {
            if (tj.scc[nxt] == tj.scc[i]) continue;
            deg[tj.scc[nxt]]++;
            e[tj.scc[i]].push_back(tj.scc[nxt]);
        }
    }
    queue<int> q;
    for (int i = 1; i <= tj.cnt; i++) {
        if (deg[i] == 0) q.push(i);
    }
    int ans = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        sum[x] += dp[x];
        ans = max(ans, sum[x]);
        for (int nxt : e[x]) {
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], sum[x]);
            if (deg[nxt] == 0) q.push(nxt);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}