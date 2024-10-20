#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cin >> s;
    string ans = string(n, '0');
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i - 1] == '0') {
            if (i == n - 1 || s[i + 1] == '0') {
                ans[i] = s[i];
            } else {
                ans[i] = '1';
            }
        } else {
            if (i == n - 1 || s[i + 1] == '0') {
                ans[i] = s[i];
            } else {
                if (s[i] == '0') ans[i] = '1';
            }
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