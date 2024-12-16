#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    int l = 1, r = 2;
    int ans = 0;

    while (q--) {
        char c;
        int t;
        cin >> c >> t;
        
        if (c == 'R') swap(l, r);

        if ((r - l) * (r - t) < 0) {
            ans += (min(l, t) + n - max(l, t)) % n;
        } else {
            ans += abs(l - t);
        }
        l = t;

        if (c == 'R') swap(l, r);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}