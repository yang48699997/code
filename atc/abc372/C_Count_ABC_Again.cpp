#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    int ans = 0;
    vector<int> ok(n - 2);

    string t = "ABC";
    for (int i = 0; i < n - 2; i++) {
        if (s.substr(i, 3) == t) {
            ok[i] = 1;
            ans++;
        }
    }

    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        s[p] = c;

        for (int i = max(p - 2, 0); i < min(n - 2, p + 1); i++) {
            ans -= ok[i];
            ok[i] = 0;
            if (s.substr(i, 3) == t) {
                ok[i] = 1;
                ans++;
            }
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