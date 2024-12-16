#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k > n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    k = n - k + 1;
    for (int i = 0; i < n; i++) {
        cout << i % k + 1 << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}