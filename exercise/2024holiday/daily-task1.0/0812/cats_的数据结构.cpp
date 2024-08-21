#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        int fa;
        cin >> fa;
        fa--;
        e[fa].push_back(i);
    }

    vector<int> a(n), b(n);

    vector<int> m(n);
    iota(m.begin(), m.end(), 0);

    auto dfs2 = [&](auto &&self, int x) -> void {
        for (int nxt : e[x]) {
            self(self, nxt);
            m[x] = min(m[x], m[nxt]);
        }
    };
    dfs2(dfs2, 0);
    int t1 = n, t2 = 1;
    auto dfs = [&](auto &&self, int x) -> void {
        a[x] = t1--;
        sort(e[x].begin(), e[x].end(), [&](int x1, int x2) {
            return m[x1] > m[x2]; 
        });
        for (int nxt : e[x]) {
            self(self, nxt);
        }
        b[x] = t2++;
    };

    dfs(dfs, 0);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << " \n"[i == n - 1];
    }
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