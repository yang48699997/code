#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int p = n + 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            p = i + 1;
            break;
        }
    }
    for (int i = 0; i < p - 1; i++) {
        if (s[i] != t[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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