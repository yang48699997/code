#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;

    int cnt = 0;
    int n = s.size();
    string t = "1100";
    for (int i = 0; i < n - 3; i++) {
        if (s.substr(i, 4) == t) cnt++;
    }

    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        for (int i = max(0, p - 3); i < min(n - 3, p + 3); i++) {
            if (s.substr(i, 4) == t) cnt--;
        }

        s[p] = c;

        for (int i = max(0, p - 3); i < min(n - 3, p + 3); i++) {
            if (s.substr(i, 4) == t) cnt++;
        }

        if (cnt) cout << "YES\n";
        else cout << "NO\n";
    }
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