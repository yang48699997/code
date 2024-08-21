#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    map<int, int> mp;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += j - i - 1;
            ans -= mp[pre[i] + pre[j]] * 2;
            mp[pre[i] + pre[j]]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        ans -= mp[pre[i] * 2];
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