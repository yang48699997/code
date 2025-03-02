#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ans(n);

    auto cal = [&](auto &&self, int l, int r, int f) -> void {
        int d = r - l;

        if (d == (d & -d)) {
            for (int i = l; i < r; i++) {
                ans[i] += f;
            }
            return;
        }

        int x = d - (1 << __lg(d));
        self(self, l, l + x, f);
        self(self, r - x, r, f);
    };

    for (int p = 0; p < 31; p++) {
        if (k & 1 ^ 1) {
            k >>= 1;
            continue;
        }
        k >>= 1;

        cal(cal, 0, n, 1 << p);
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