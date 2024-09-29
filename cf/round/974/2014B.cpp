#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int ok = 1;
    if (n & 1) {
        k--;
        if (k % 4 == 3 || k % 4 == 2) ok = 1;
        else ok = 0;
    } else {
        if (k % 4 == 0 || k % 4 == 1) ok = 1;
        else ok = 0;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
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