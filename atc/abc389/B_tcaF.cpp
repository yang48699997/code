#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x;
    cin >> x;

    ll a = 1;
    while (x > 1) {
        x /= a;
        a++;
    }

    cout << a - 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}