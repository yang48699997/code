#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n, b, x;
    cin >> n >> b >> x;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
    sort(a.begin(), a.end());
    vector<int> cnt(mx + 1);
    for (int i : a) cnt[i++];
    ll ans = 0;
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}