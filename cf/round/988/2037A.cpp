#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += v[x];
        v[x] ^= 1;
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