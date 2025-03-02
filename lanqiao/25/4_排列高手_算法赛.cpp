#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "2\n";
        return;
    } else if (n == 2) {
        cout << "6\n";
        return;
    }

    ll ans = 1LL * (n - 1) * n / 2;
    ans += 2LL * (n - 1);
    ans += n + 1;


    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}