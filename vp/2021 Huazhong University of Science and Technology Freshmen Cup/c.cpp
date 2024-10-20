#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll ans = n * 2 + 2;
    ans *= n;
    ans += n * n;
    ans += n * 4;
    ans += 4;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}