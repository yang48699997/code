#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> l(n), r(n), deg(n);
    vector<vector<int>> e(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if (n == 1) {
        cout << l[0] << "\n";
        return;
    }

    ll add = 0;
    vector<ll> val(n);
    queue<int> q;
    vector<int> v(n), inq(n);

    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            q.push(i);
            inq[i] = 1;
        }
    }

    ll ans = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        v[x] = 1;
        ll now = val[x] + add + l[x];
        ans = max(ans, now);
        // cerr << x + 1 << ' ' << now << "\n";
        // cerr << l[x] << ' ' << r[x] << "\n";
        // cerr << "===============\n";

        for (int nxt : e[x]) {
            if (v[nxt]) continue;
            else if (inq[nxt]) {
                if (now > r[nxt] + val[nxt] + add) {
                    ll tmp = now - r[nxt] - val[nxt] - add;
                    add += tmp;
                    l[nxt] = r[nxt];
                } else {
                    l[nxt] = max(l[nxt], now - add - val[nxt]);
                }
            } else {
                if (now > r[nxt] + val[nxt] + add) {
                    ll tmp = now - r[nxt] - val[nxt] - add;
                    add += tmp;
                    l[nxt] = r[nxt];
                } else {
                    l[nxt] = max(l[nxt], now - add - val[nxt]);
                }
                deg[nxt]--;
                if (deg[nxt] == 1) {
                    q.push(nxt);
                    inq[nxt] = 1;
                }
            }
        }
    }

    cout << ans << "\n";
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