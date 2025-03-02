#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    int lef = k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= lef) {
            lef -= x;
        } else {
            ans++;
            lef = k - x;
        }
    }

    if (lef < k) ans++;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}