#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<ll, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ll p = i;
        p *= n - i - 1;
        p += n - 1;
        cnt[p] += 1;
    }
    for (int i = 0; i < n - 1; i++) {
        ll p = i + 1;
        p *= (n - i - 1);
        cnt[p] += a[i + 1] - a[i] - 1;
    }
    while (q--) {
        ll x;
        cin >> x;
        cout << cnt[x] << " \n"[q == 0];
    }
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