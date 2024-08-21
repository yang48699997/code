#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    string ans;

    int n = s.length();
    int m = t.length();
    int l = 0;
    for (int i = 0; i < m; i++) {
        while (l < n && (s[l] != t[i] && s[l] != '?')) {
            ans += s[l];
            l++;
        }
        if (l == n) {
            cout << "NO\n";
            return;
        }
        ans += t[i];
        l++;
    }
    while (l < n) {
        if (s[l] != '?') ans += s[l++];
        else {
            ans += 'a';
            l++;
        }
    }
    cout << "YES\n";
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