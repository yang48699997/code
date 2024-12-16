#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << max(max({a, b, c}), a + b + c - max({a, b, c})) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}