#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    int x;
    cin >> x;
    int ans = -1;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        if (p > x) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}