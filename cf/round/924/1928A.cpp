#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a % 2 == 0) {
        int p = a / 2;
        int q = b * 2;
        if (p > q) swap(p, q);
        if (p != a || q != b) {
            cout << "Yes\n";
            return;
        }
    }
    if (b % 2 == 0) {
        int p = a * 2;
        int q = b / 2;
        if (p > q) swap(p, q);
        if (p != a || q != b) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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