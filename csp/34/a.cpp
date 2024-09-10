#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        cout << x << " \n"[i % q == q - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}