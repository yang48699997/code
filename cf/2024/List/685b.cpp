#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> e(n);
    vector<int> fa(n, -1);
    for (int i = 1; i < n; i++) {
        int f;
        cin >> f;
        f--;
        e[f].push_back(i);
        fa[i] = f;
    }
    vector<int> cen(n), siz(n), son(n);

    auto dfs = [&](auto &&self, int x) -> void {
        siz[x] = 1;
        cen[x] = x;
        int mx = 0, p = -1;
        for (int nxt : e[x]) {
            self(self, nxt);
            siz[x] += siz[nxt];
            if (siz[nxt] > mx) {
                mx = siz[nxt];
                p = nxt;
            }
        }
        son[x] = mx;
        if (son[x]) {
            cen[x] = cen[p];
            while (max(siz[x] - siz[cen[x]], son[cen[x]]) > siz[x] / 2) {
                cen[x] = fa[cen[x]];
            }
        }
    };

    dfs(dfs, 0);

    while (q--) {
        int x;
        cin >> x;
        x--;
        cout << cen[x] + 1 << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}