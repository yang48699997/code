#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<ll> cnt(n, 1);
    vector<vector<int>> e(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            x--;
            e[i].push_back(x);
            cnt[i] += cnt[x];
            if (cnt[i] >= inf) cnt[i] = inf;
        }
    }

    ll m;
    cin >> m;
    int now = n - 1;
    while (1) {
        int t = e[now].size();
        int ok = 1;
        for (int i = 0; i < t; i++) {
            if (cnt[e[now][i]] >= m) {
                now = e[now][i];
                ok = 0;
                break;
            } else {
                m -= cnt[e[now][i]];
            }
        }
        if (m == 1 && ok) {
            cout << now + 1 << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}