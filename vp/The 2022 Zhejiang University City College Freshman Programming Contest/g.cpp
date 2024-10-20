#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {y, y + n - x};
    }

    ll ans = 0;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; ) {
        int cl = p[i].first;
        int cr = p[i].second;
        int j = i;
        while (j < n && p[j].first <= cr) {
            cr = max(cr, p[j].second);
            j++;
        }
        ans += (cr - cl + 2) * 1LL * (cr - cl + 1) / 2; 
        i = j;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}