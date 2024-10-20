#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int ans = 0;
    if (n != m) ans = min(n, m) + 1;
    for (int i = 0; i < min(n, m); i++) {
        if (s1[i] != s2[i]) {
            ans = i + 1;
            break;
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