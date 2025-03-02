#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    if (accumulate(a.begin(), a.end(), 0LL) != accumulate(b.begin(), b.end(), 0LL)) {
        cout << "No\n";
        return;
    }

    map<int, int> cnt;
    set<int> v;

    v.insert(0);

    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    auto dfs = [&](auto &&self, int x) -> int {
        if (v.count(x)) return 0;
        if (cnt.find(x) == cnt.end()) {
            if (x == 1) return 0;
            int res = ((self(self, x / 2) & self(self, x / 2 + x % 2)));
            if (res == 0) v.insert(x);
            return res;
        } else {
            if (--cnt[x] == 0) cnt.erase(x);
            return 1;
        }

        return 0;
    };

    for (int i = 0; i < m; i++) {
        if (!dfs(dfs, b[i])) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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