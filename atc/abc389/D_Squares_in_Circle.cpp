#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int R;
    cin >> R;

    ll ans = 0;
    int x = R;

    for (int i = 0; i < R; i++) {
        while ((2LL * i + 1) * (2LL * i + 1) + (2LL * x + 1) * (2LL * x + 1) > 4LL * R * R) x--;
        ans += x * 2 + 1;
        if (i) ans += x * 2 + 1; 
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}