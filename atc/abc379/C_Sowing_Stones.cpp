#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    ll sum = 0;
    vector<array<ll, 2>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i][0];
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i][1];
        sum += a[i][1];
    }

    if (sum != n) {
        cout << "-1\n";
        return;
    }

    sort(a.begin(), a.end());

    ll now = 0;
    ll ans = 0;

    if (a[0][0] != 1) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < m - 1; i++) {
        int nxt = a[i + 1][0];
        now += a[i][1];
        if (nxt - a[i][0] > now) {
            cout << "-1\n";
            return;
        }
        ll d = nxt - a[i][0];
        ans += d * (d - 1) / 2;
        now -= d;
        ans += now * d;
    }

    ll d = n - a.back()[0];
    ans += d * (d + 1) / 2;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}