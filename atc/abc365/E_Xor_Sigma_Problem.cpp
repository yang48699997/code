#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    vector<int> p(n);
    vector<int> pre(n);
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < n; j++) {
            if (1 << i & a[j]) p[j] = 1;
            else p[j] = 0;
        }
        vector<int> cnt(2);
        int pre = 0;
        for (int j = 0; j < n; j++) {
            pre ^= p[j];
            cnt[pre]++;
        }
        ll sum = 0;
        pre = 0;
        for (int j = 0; j < n; j++) {
            sum += cnt[pre ^ 1];
            if ((pre ^ 1) == (pre ^ p[j])) sum--;
            pre ^= p[j];
            cnt[pre]--;
        }
        ans += sum * (1 << i);
        // cerr << sum << "\n";
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}