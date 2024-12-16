#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int now = 0;
    int cnt = 0;

    while (abs(now) <= n) {
        cnt++;
        if (cnt & 1) now -= 2 * cnt - 1;
        else now += 2 * cnt - 1;
    }

    if (cnt % 2 == 0) cout << "Kosuke\n";
    else cout << "Sakurako\n";
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