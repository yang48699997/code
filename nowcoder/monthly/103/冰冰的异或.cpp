#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

void solve() {
    ll n;
    cin >> n;

    if (n == 2) {
        cout << "1\n";
        return;
    }
    int p = 0;
    int cnt = 0;
    for (int i = 0; i <= 60; i++) {
        if ((1ll << i) <= n) p = i;
        if (1ll << i & n) cnt++;
    }
    if (cnt > 1) p++;
    cout << (1ll << p) << "\n";

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