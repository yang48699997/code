#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    n -= 2;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ) {
        if (a[i] == 1) {
            i++;
            continue;
        } else {
            int j = i;
            while (j < n && a[j] == 0) {
                j++;
            }

            if (j - i == 1 && i > 0 && i < n - 1) {
                cout << "NO\n";
                return;
            }

            i = j;
        }
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