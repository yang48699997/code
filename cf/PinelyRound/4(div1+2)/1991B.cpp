#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> b[i];
    vector<int> ans(n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 30; j++) {
            if (1 << j & b[i]) {
                ans[i] |= (1 << j);
                ans[i + 1] |= (1 << j);
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int p = (ans[i] & ans[i + 1]);
        if (p != b[i]) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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