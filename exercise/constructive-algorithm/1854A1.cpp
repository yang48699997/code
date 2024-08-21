#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0, mi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mi = min(mi, a[i]);
    }
    if (mx == 0) {
        cout << n - 1 << "\n";
        for (int i = n - 1; i > 0; i--) {
            cout << i << " " << i + 1 << "\n";
        }
        return;
    } else if (mi == 0) {
        cout << n - 1 << "\n";
        for (int i = 2; i <= n; i++) {
            cout << i << " " << i - 1 << "\n";
        }
        return;
    } else {
        vector<int> cnt(2);
        vector<int> p(2);
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) cnt[0]++;
            else if (a[i] < 0) cnt[1]++;
            if (a[i] == mx) p[0] = i;
            else if (a[i] == mi) p[1] = i;
        }
        vector<pair<int, int>> ans;
        int ok = 0;
        if (!ok) {
            int c = 0;
            int cur = mx;
            while (cur + mi < 0) {
                c++;
                cur *= 2;
            }
            if (c + cnt[1] <= 12) {
                ok = 1;
                for (int i = 0; i < c; i++) {
                    ans.emplace_back(p[0], p[0]);
                }
                for (int i = 0; i < n; i++) {
                    if (a[i] < 0) ans.emplace_back(i, p[0]);
                }
                for (int i = 1; i < n; i++) {
                    ans.emplace_back(i, i - 1);
                }
            }
        }
        if (!ok) {
            int cur = mi;
            while (cur + mx > 0) {
                ans.emplace_back(p[1], p[1]);
                cur *= 2;
            }
            for (int i = 0; i < n; i++) {
                if (a[i] > 0) ans.emplace_back(i, p[1]);
            }
            for (int i = n - 2; i >= 0; i--) {
                ans.emplace_back(i, i + 1);
            }
        }
        cout << ans.size() << "\n";
        for (auto [x, y] : ans) {
            x++;
            y++;
            cout << x << " " << y << "\n";
        }
    }
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