#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    
    if (n == 1 || m == 1) {
        cout << "YES\n";
        return;
    }
    int ok = 0;
    int p = sqrt(n);
    for (int i = 2; i <= p; i++) {
        if (n % i == 0) {
            ok = (i <= m);
            break;
        }
    }
    ok |= (n <= m);
    if (ok) cout << "NO\n";
    else cout << "YES\n";
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