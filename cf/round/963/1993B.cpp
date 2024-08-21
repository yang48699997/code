#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> cnt(2);
    int mx1 = -1, mx2 = -1;
    vector<ll> b;
    for (int i = 0; i < n; i++) {
        cnt[a[i] % 2]++;
        if (a[i] % 2) mx1 = max(mx1, a[i]);
        else b.push_back(a[i]);
    } 
    if (cnt[0] == n || cnt[1] == n) {
        cout << "0\n";
        return;
    }
    int ans = 0;
    ll now = mx1;
    for (int j : b) {
        if (now > j) {
            now += j;
            ans++;
        } else {
            ans += 2;
            now = 1e9;
        }
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