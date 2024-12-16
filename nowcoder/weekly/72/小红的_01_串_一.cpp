#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s.substr(i, 2) == "01" || s.substr(i, 2) == "10") ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}