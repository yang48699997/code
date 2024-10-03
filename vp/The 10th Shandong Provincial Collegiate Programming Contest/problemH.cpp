#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    int x = 0, y = 0;
    string s;
    cin >> s;
    vector<ll> cx, cy;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') y++;
        else if (s[i] == 'D') y--;
        else if (s[i] == 'L') x--;
        else x++;
        cx.emplace_back(x);
        cy.emplace_back(y);
    }
    ll px = x * (k - 1);
    ll py = y * (k - 1);

    ll ans = abs(x) + abs(y);
    for (int i = 0; i < n; i++) {
        ans = max({ans, abs(cx[i]) + abs(cy[i]), abs(px + cx[i]) + abs(py + cy[i])});
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