#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int k;
    string s;
    cin >> k >> s;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
    }
    int p = (m - n + 1);
    p %= k;
    if (s[p] == '1') cout << "2\n";
    else cout << "1\n";

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