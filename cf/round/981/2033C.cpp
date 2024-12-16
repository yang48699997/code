#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n / 2; i++) {
        int r = n - 1 - i;
        if ((a[i] == a[i - 1]) + (a[r] == a[r + 1]) > (a[i] == a[r + 1]) + (a[r] == a[i - 1])) {
            swap(a[i], a[r]);
        }
    }
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        ans += (a[i] == a[i + 1]);
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