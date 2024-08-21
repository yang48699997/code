#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) cnt[i] += 2;
            if (j * j == i) cnt[i]--;
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += cnt[i] * cnt[n - i];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}