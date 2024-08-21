#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    stack<pair<ll, int>> stk;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        ll d = 0;
        ans = max(ans, a);
        while (!stk.empty() && (a >= stk.top().first || b == stk.top().second)) {
            if (stk.top().second == b) {
                a = a - d + stk.top().first;
                d = 0;
                ans = max(ans, a);
            } else {
                d = max(d, stk.top().first);
            }
            stk.pop();
        }
        stk.push({a, b});
        cout << ans << " \n"[i == n - 1];
    }
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