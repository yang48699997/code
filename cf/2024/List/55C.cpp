#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    int ok = 0;

    while (k--) {
        int x, y;
        cin >> x >> y;
        int d = min({abs(x - 1), abs(x - n), abs(y - 1), abs(y - m)});
        if (d < 5) ok = 1;
    }
    
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}