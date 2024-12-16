#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> ans(n + 1);
    vector<ll> odd(n + 1), even(n + 1);

    ll pre = 0;
    for (int i = 0; i < n / 2; i++) {
        ll d = a[n - i - 1] - a[i] - pre;
        pre = d;
        ans[i % 2] += d;
        ans[i + 2] -= d;
        ans[n - i] += d;
    }

    for (int i = 0; i < n; i++) {
        if (i > 1) {
            ans[i] += ans[i - 2];
        }

        a[(i - 1 + n) % n] += ans[i];
        a[i] += ans[i] * 2;
        a[(i + 1) % n] += ans[i];
    }

    for (int i = n - 1; i > 0; i--) {
        if (i > 1) ans[i] -= ans[i - 2];
    }

    pre = 0;
    for (int i = n / 2; i > 0; i--) {
        ll d = a[i - 1] + pre - a[i];
        pre = -d;
        ans[i] += d;
        if (n - i + 1 < n) ans[n - i + 1] -= d;
    }

    for (int i = 1; i < n; i++) {
        if (i > 1) ans[i] += ans[i - 2];
    }

    ll mi = *min_element(ans.begin(), ans.end() - 1);

    for (int i = 0; i < n; i++) {
        cout << ans[i] - mi << " \n"[i == n - 1];
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