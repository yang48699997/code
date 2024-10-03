#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    if (s[0] != t[0] || s.back() != t.back() || (n -  m) % 2) {
        cout << "NO\n";
        return;
    }
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    int l = 1;
    for (int i = 1; i < n - 1; ) {
        if (l < m - 1 && s[i] == t[l]) {
            l++;
            i++;
        } else i += 2;
    }
    if (l == m - 1) cout << "YES\n";
    else cout << "NO\n";
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