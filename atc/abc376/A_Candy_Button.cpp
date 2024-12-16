#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, t;
    cin >> n >> t;
    
    int ans = 0;
    int pre = -1000;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (pre + t <= x) {
            pre = x;
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}