#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    if (n % 3 == 0) {
        cout << "1 " << n / 3 << "\n";
    } else {
        cout << "0 " << n % 3 + n / 3 << "\n"; 
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