#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, c1, c2;
    cin >> n >> c1 >> c2;

    if (c1 * 2 <= c2) {
        cout << n * c1 * 3 << "\n";
    } else {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int lef = 3;
            if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) {
                ans += c2;
                lef -= 2;
            }
            ans += lef * min(c1, c2);
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}