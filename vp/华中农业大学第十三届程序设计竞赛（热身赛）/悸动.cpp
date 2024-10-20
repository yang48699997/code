#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, h, d;
    cin >> n >> h >> d;
    cout << h * d / (n - h) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}