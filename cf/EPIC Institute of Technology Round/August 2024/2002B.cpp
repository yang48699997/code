#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int l1 = 0, r1 = n - 1;
    int l2 = 0, r2 = n - 1;
    for (int i = 0; i < n - 1; i++) {
        int ok1 = (a[l1] == b[l2] || a[l1] == b[r2]);
        int ok2 = (a[r1] == b[l2] || a[r1] == b[r2]);
        if (ok1 && ok2) {
            if (a[l1] == b[l2]) {
                l1++;
                l2++;
            } else {
                l1++;
                r2--;
            }
        } else {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
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