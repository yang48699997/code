#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int Q;
    cin >> Q;

    queue<ll> q;
    ll now = 0;

    while (Q--) {
        int c;
        cin >> c;
        if (c == 1) {
            q.push(now);
        } else if (c == 2) {
            int x;
            cin >> x;
            now -= x;
        } else {
            ll x;
            cin >> x;
            x += now;
            int ans = 0;
            while (!q.empty() && q.front() >= x) {
                ans++;
                q.pop();
            }

            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}