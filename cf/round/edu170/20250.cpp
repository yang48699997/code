#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int ans = n + m;
    int l = 0;
    for (int i = 0; i < min(n, m); i++) {
        if (s1[i] == s2[i]) l++;
        else break;
    }

    if (l) ans = ans - l + 1;
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