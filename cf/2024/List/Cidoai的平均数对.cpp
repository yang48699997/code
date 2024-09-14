#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p.emplace_back(a, b);
    }
    int ans = 0;
    sort(p.begin(), p.end(), [&](int x1, int x2) {
        return p[x1].first < p[x2].first;
    });
    for (int i = 1; i <= n; i++) {
        int mx = i * k;
        int res = 0;
        int tot = 0;
        priority_queue<pair<int, int>> q;

        for (int j = 0; j < i - 1; j++) {
            tot += b[j];
            res += a[j];
            q.emplace(-b[j], a[j]);
        }
        for (int j = i; j < n; j++) {
            auto [x, y] = q.front();
            if (b[j] + x >= 0) {
                
            }
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