#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    cout << "1 1 2 ";

    for (int i = 0; i < n - 5; i++) {
        cout << 3 + i << " ";
    }

    cout << "1 2\n";
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