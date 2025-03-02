#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;

    vector<int> a(n);

    if (n & 1) {
        for (int i = 1; i < n; i += 2) {
            a[i] = 1;
        }
        a.back() = 2;
        if (x % 2 == y % 2) {
            if (x & 1) {
                a[x]++;
            } else {
                a[y] = 2;
                int now = 0;
                for (int i = y + 1; i < n; i++) {
                    a[i] = now;
                    now ^= 1;
                }
            }
        }
    } else {
        for (int i = 1; i < n; i += 2) {
            a[i] = 1;
        }
        if (x % 2 == y % 2) {
            if (x & 1) {
                a[x]++;
            } else {
                a[x] += 2;
            }
        }
        
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
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