#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> p(n, 1);
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == 1 && a[i - 1] != 1) {
            cout << "-1\n";
            return;
        } else if (a[i - 1] == 1) continue;
        int c = 0;
        ll cur = a[i];
        while (cur < a[i - 1]) {
            cur *= cur;
            c++;
        }
        cur = a[i - 1] * a[i - 1];
        while (cur <= a[i] && p[i - 1] > 1) {
            cur *= cur;
            p[i - 1]--;
        }
        p[i] += c + p[i - 1] - 1;
        // cerr << p[i] << " \n"[i == n - 1];
        ans += p[i] - 1;
    }
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