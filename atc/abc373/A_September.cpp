#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n = 12;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s.size() == i) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}