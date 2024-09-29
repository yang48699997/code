#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mx = 2e6;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> a[i];
    }
    d.push_back(mx);
    a.push_back(0);
    deque<pair<int, int>> q;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        q.push_back({d[i - 1], a[i - 1]});
        int x = d[i] - d[i - 1];
        x = min(x, k);
        int r = d[i - 1];
        int now = 0;
        int lef = 0;
        while (!q.empty()) {
            auto [pd, pa] = q.back();
            q.pop_back();
            int num = (pa + lef) / m;
            num = min(num, x - now);
            if (now + num + r > pd + k) {
                now += max(0, pd + k - now - r);
                q.clear();
            } else {
                now += num;
                lef = lef + pa - num * m;
                if (q.empty() || now == x) {
                    q.push_back({pd, lef});
                    break;
                }       
            }
        }
        if (now != x) q.clear();
        // cerr << now << " ";
        ans += now;
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