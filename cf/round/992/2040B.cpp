#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;

    int ans = 1;
    int now = 1;

    while (now < n) {
        ans++;
        now = (now + 1) * 2;
    }

    cout << ans << "\n";
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