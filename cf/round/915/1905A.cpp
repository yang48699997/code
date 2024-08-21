#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, m;
    cin >> n >> m;
    cout << max(n, m) << "\n";
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