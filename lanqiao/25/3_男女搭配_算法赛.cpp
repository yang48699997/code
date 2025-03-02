#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int l = 0, r = m;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (mid * 2 > n || mid > m || n + m - mid * 3 < k) r = mid - 1;
        else l = mid + 1;
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