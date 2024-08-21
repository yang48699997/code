#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, m;
    cin >> n >> m;
    if (n >= m && (n - m) % 2 == 0) cout << "Yes\n";
    else cout << "No\n";
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