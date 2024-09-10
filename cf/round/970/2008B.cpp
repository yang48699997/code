#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (sqrt(n) * sqrt(n) != n) {
        cout << "No\n";
        return;
    }
    int ok = 1;
    for (int i = 0; i < sqrt(n); i++) {
        for (int j = 0; j < sqrt(n); j++) {
            if (i == 0 || j == 0 || i == sqrt(n) - 1 || j == sqrt(n) - 1) {
                if (s[i * sqrt(n) + j] == '0') ok = 0; 
            } else if (s[i * sqrt(n) + j] == '1') ok = 0; 
        }
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
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