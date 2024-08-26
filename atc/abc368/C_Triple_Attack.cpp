#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    ll ans = 0;
    int now = 0;
    for (int i : h) {
        if (now == 1) {
            i--;
            now = 2;
            ans++;
            if (i <= 0) continue;
        } 
        if (now == 2) {
            ans++;
            i -= 3;
            now = 0;
        }
        if (i <= 0) continue;
        ans += i / 5 * 3;
        i %= 5;
        if (i == 1) {
            now = 1;
            ans++;
        } else if (i == 2) {
            now = 2;
            ans += 2;
        } else if (i > 2) {
            ans += 3;
            now = 0;
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