#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<char> c(n);
    for (int i = 0; i < n; i++) cin >> c[i] >> a[i];

    vector<int> ans(2);
    for (int i = 0; i < 10; i++) {
        int p0 = 0, p1 = 1;
        for (int j = 0; j < n; j++) {
            int d = a[j] & 1;
            a[j] >>= 1;
            if (c[j] == '|') {
                p0 |= d;
                p1 |= d;
            } else if (c[j] == '&') {
                p0 &= d;
                p1 &= d;
            } else {
                p0 ^= d;
                p1 ^= d;
            }
        }
        if (p0 == 0) {
            if (p1 == 1) {
                ans[0] |= (1 << i);
            }
        } else {
            ans[1] |= (1 << i);
            if (p1 == 0) {
                ans[0] |= (1 << i);
            }
        }
    }

    cout << 2 << "\n";
    cout << "& " << ans[0] << "\n";
    cout << "^ " << ans[1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}