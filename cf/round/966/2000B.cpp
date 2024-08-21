#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> a(n);
    int x;
    cin >> x;
    v[x - 1] = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int x = a[i] - 1;
        if (v[x]) {
            cout << "NO\n";
            return;
        }
        v[x] = 1;
        if (x > 0 && v[x - 1]) continue;
        if (x < n - 1 && v[x + 1]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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