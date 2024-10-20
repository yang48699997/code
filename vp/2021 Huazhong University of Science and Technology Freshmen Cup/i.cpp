#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = n;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        int p = it -> first;
        int res = it -> second;
        if (p >= n) break;
        if (n >= min(p + res / 2 + res % 2, p * 2) || p > res - 1 || (p == res - 1 && res == n)) {
            ans = min(ans, n - res);
        } else {
            int l = 1, r = res;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (n >= min(p + mid / 2 + mid % 2, p * 2) || p > mid - 1 || (p == mid - 1 && mid == n)) l = mid + 1;
                else r = mid - 1;
            }
            res = r;
            ans = min(ans, n - res);
            if (res == 0) continue;
        }
        if (cnt.count(p + 1)) {
            if (res - 1 == p) continue;
            int c = cnt[p + 1];
            int l = 1, r = c;
            int add = p + 1 - res;
            while (l <= r) {
                int mid = (r + l) / 2;
                if (res + max(min(add * 2, add + mid / 2 + mid % 2), mid) <= n) {
                    l = mid + 1;
                } else r = mid - 1;
            }
            c = r;
            ans = min(ans, n - c - res);
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