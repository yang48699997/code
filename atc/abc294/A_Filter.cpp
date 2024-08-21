#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) cout << x << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}