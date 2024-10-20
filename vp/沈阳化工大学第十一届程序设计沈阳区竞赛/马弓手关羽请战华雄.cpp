#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int l = 1;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        l = max(l, i + x);
        if (l >=n) {
            cout << "YES\n";
            return;
        }
        if (l == i) {
            cout << "NO\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}