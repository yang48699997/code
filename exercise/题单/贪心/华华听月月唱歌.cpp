#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        p.emplace_back(l, r);
    }
    sort(p.begin(), p.end());
    int r = 0;
    int l = 0;
    int mx = 0;
    int ans = 0;
    while (r < n) {
        while (l < m && p[l].first <= r + 1) {
            mx = max(mx, p[l].second);
            l++;
        }
        if (mx <= r) break;
        else {
            ans++;
            r = mx;
        }
    }
    cout << (r == n ? ans : -1) << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}