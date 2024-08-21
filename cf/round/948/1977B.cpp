#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int x;
    cin >> x;
    vector<int> ans(32);
    for (int i = 0; i < 32; i++) {
        if (x & 1) {
            if (x >> 1 & 1) {
                ans[i] = -1;
                x += (x & -x);
            } else {
                ans[i] = 1;
            }
        }
        x >>= 1;
    }
    cout << 32 << "\n";
    for (int i = 0; i < 32; i++) cout << ans[i] << " \n"[i == 31];
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