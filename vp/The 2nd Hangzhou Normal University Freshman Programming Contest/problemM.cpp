#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }

    int ok = 1;
    map<int, vector<int>> e;
    auto dfs = [&](auto &&self, int l1, int r1, int l2, int r2, int only) -> int {
        if (l1 >= r1) return a[r1];
        int now = a[l1];
        l1++;
        r2--;
        if (a[l1] == b[r2]) {
            ok = 0;
            int res = self(self, l1, r1, l2, r2, 0);
            if (now < res) {
                e[now].push_back(-1);
            }
            e[now].push_back(a[l1]);
            return min(res, now);
        } else {
            e[now].push_back(a[l1]);
            int p = pos[a[l1]];
            int len = p - l2;
            int res = self(self, l1, l1 + len, l2, l2 + len, 0);
            l1 = l1 + len + 1;
            l2 = l2 + len + 1;
            e[now].push_back(a[l1]);
            self(self, l1, r1, l2, r2, 0);
            return res;
        }
    };

    dfs(dfs, 0, n - 1, 0, n - 1, 0);
    int cnt = 0;
    auto work = [&](auto &&self, int x) -> void {
        if (x == -1) return;
        if (e.count(x) && e[x].size() > 0) self(self, e[x][0]);
        cout << x << " \n"[++cnt == n];
        if (e.count(x) && e[x].size() > 1) self(self, e[x][1]);
        return;
    };
    
    if (ok) cout << "Yes\n";
    else cout << "No\n";
    work(work, a[0]);
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