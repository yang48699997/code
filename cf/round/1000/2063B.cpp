#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    
    l--;
    r--;
    vector<int> a(n);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto cal = [&](int l1, int r1) -> ll {
        int cnt = r - l + 1;
        vector<int> b(a.begin() + min(l, l1), a.begin() + max(r, r1) + 1);
        sort(b.begin(), b.end());

        ll res = 0;
        while (cnt--) {
            res += b[cnt];
        }

        return res;
    };

    cout << min(cal(0, l - 1), cal(r + 1, n - 1)) << "\n";
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