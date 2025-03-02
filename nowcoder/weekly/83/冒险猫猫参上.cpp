#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    int p = 0;

    for (int i = 0; i < n; i++) {
        cout << 1 + p << " \n"[i == n - 1];
        p ^= 1;
    }
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