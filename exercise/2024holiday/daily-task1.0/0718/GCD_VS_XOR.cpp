#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    ll n;
    cin >> n;
    ll ans = n - (n & -n);
    cout << (ans == 0 ? -1 : ans) << "\n";
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