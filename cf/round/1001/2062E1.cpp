#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T> 
struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int x) : n(x), a(x + 1) {};
    void build() {
        for (int i = 1; i <= n; i++) {
            int nxt = i + (i & -i);
            if (nxt <= n) a[nxt] += a[i];
        }
    }
    T query(int x) {
        T res = 0;
        while (x) {
            res += a[x];
            x -= (x & -x);
        }
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int x, T val) {
        while (x <= n) {
            a[x] += val;
            x += (x & -x);
        }
        return;
    }
};

using F = Fenwick<ll>;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> e(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> in(n), out(n), dep(n);
    int now = 0;

    auto dfs = [&](auto &&self, int x, int fa = -1, int pre = 0) -> void {
        in[x] = ++now;
        dep[x] = pre + 1;
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            self(self, nxt, x, dep[x]);
        }
        out[x] = now;
    };

    dfs(dfs, 0);

    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        if (a[x1] != a[x2]) return a[x1] > a[x2];
        return dep[x1] > dep[x2];
    });

    int mx = a[nums[0]];

    F f(n);
    for (int i = 0; i < n; i++) {
        int p = nums[i];
        f.update(in[p], 1);
        if (a[p] == mx) continue;
        if (f.query(in[p], out[p]) == i + 1) continue;
        cout << p + 1 << "\n";
        return;
    }


    cout << "0\n";
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