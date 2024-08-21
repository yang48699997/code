#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int lef = n % k;
    if (lef == 0) lef += k;
    int c = lef / 2 + 1;
    int l = 1, r = 1e9;
    vector<int> cnt(lef);
    auto check = [&](int x) -> int {
        for (int i = 0; i < lef; i++) {
            cnt[i] = -1e9;
        }
        for (int i = 0; i < n; i++) {
            if (i % k >= lef) continue;
            int p = (i % k + k - 1) % k;
            if (i % k == 0) {
                cnt[i % k] = max(cnt[i % k], (int)(a[i] >= x));
            } else cnt[i % k] = max(cnt[i % k], cnt[p] + (a[i] >= x));
        }
        return cnt[lef - 1] >= c;
    };
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << "\n";
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