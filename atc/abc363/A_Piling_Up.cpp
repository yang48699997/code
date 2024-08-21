#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    n %= 100;
    cout << 100 - n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}