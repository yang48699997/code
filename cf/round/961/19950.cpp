#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int p = n - 1;
    if (k) {
        ans++;
        k -= n;
    }
    while (k > 0) {
        ans++;
        k -= p;
        if (k > 0) {
            ans++;
            k -= p;
        }
        p--;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}