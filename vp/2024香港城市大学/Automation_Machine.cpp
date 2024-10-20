#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, q;
    cin >> n >> q;
    int ans = 0;
    ll sum = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            ll k;
            cin >> k;
            sum += k;
            if (sum > n) {
                ans++;
                sum = 0;
            }
        } else {
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