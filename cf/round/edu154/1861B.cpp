#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    string a, b;
    cin >> a >> b;
    int l1 = 0, l2 = 0;
    for (int i = 1; i < a.length(); i++) {
        if (a[i - 1] == '0' && b[i - 1] == '0' && a[i] == '1' && b[i] == '1') {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO" << "\n";
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