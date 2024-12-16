#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    int p = __lg(k);
    if ((1LL << p) < k) p++;

    if (p >= n) {
        cout << "-1\n";
        return;
    }

    vector<int> ans(n);
    ll now = (1LL << p);

    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (i < n - p - 1) {
            ans[l++] = i + 1;
        } else {
            if (now / 2 >= k) {
                now /= 2;
                ans[l++] = i + 1;
            } else {
                ll d = now / 2;
                k -= d;
                now -= d;
                ans[r--] = i + 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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