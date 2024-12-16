#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;

struct Info {
    pair<int, int> v1 = {-inf, -1};
    pair<int, int> v2 = {-inf, -1};
};

Info operator+(const Info &a, const Info &b) {
    vector<pair<int, int>> p(4);
    p[0] = a.v1;
    p[1] = a.v2;
    p[2] = b.v1;
    p[3] = b.v2;
    sort(p.begin(), p.rend());
    return {p[0], p[1]};
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n);

    const int p = 20;
    vector<vector<int>> fa(p, vector<int> (n));
    vector<vector<Info>> info(p, vector<Info> (n));
    vector<int> dep(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto dfs = [&](auto &&self, int x, int f) -> void {
        fa[0][x] = f;
        if (x == 0) dep[x] = 1;
        else dep[x] = dep[f] + 1;
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            self(self, nxt, x);
        }

    };
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