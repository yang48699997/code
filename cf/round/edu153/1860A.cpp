#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (s == "()") {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string ans;
    for (int i = 0; i < n; i++) ans += '(';
    for (int i = 0; i < n; i++) ans += ')';
    int ok = 1;
    for (int i = 0; i <= n; i++) {
        // cerr << ans.substr(i, n) << "\n";
        if (ans.substr(i, n) == s) {
            ok = 0;
            break;
        }
    }
    if (!ok) {
        for (int i = 0; i < n; i++) cout << "()";
        cout << "\n";
    } else cout << ans << "\n";
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