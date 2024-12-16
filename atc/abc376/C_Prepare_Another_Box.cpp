#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b[i]) {
            cout << "-1\n";
            return;
        }
    }

    for (int i = n - 1; i > 0; i--) {
        if (a[i] > b[i - 1]) {
            cout << a[i] << "\n";
            return;
        }
    }

    cout << a[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}