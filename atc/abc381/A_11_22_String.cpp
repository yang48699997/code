#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (~n & 1) {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < n / 2; i++) {
        if (s[i] != '1') {
            cout << "No\n";
            return;
        }
    }

    if (s[n / 2] != '/') {
        cout << "No\n";
        return;
    }

    for (int i = n / 2 + 1; i < n; i++) {
        if (s[i] != '2') {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}