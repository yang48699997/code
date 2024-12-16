#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    cout << b * 2 - a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}