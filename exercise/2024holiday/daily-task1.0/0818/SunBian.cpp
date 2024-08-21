#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (k >= n) cout << 'A';
    else if (k == 1) {
        if (n & 1) cout << 'A';
        else cout << 'B';
    } else {
        cout << 'B';
    }
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