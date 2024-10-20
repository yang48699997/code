#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ok = 0;
    if (s[0] != '1') ok = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != '0') ok = 1;
    }
    if (ok) {
        cout << 1;
        for (int i = 0; i < n; i++) {
            cout << 0;
        }
        cout << "\n";
    } else {
        cout << "-1\n";
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