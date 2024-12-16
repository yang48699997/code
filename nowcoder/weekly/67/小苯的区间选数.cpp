#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    ll l = l1 + l2;
    ll r = r1 + r2;
    string L = to_string(l);
    string R = to_string(r);

    reverse(L.begin(), L.end());
    while (L.size() < R.size()) L += '0';
    reverse(L.begin(), L.end());

    int ans = 0;
    int res = 0;
    for (int i = 0; i < R.size(); i++) {
        if (L[i] == R[i]) res += L[i] - '0';
        else {
            ans = max(ans, res + R[i] - '0' - 1 + 9 * (int)(R.size() - i - 1));
            res += R[i] - '0';
        }
    }
    ans = max(ans, res);

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