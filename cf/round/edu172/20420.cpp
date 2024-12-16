#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int now = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (now + a[i] > k) {
            break;
        } else {
            now += a[i];
        }
    }

    cout << k - now << "\n";
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