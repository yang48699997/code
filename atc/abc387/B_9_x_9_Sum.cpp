#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n = 9;
    int x;
    cin >> x;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i * j == x) continue;
            ans += i * j;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}