#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m + 2, m + 1);
    vector<int> tmp(m + 2);
    int ok = 1;
    vector<int> p1(n), p2(n), p3(n);
    for (int i = 0; i < n; i++) {
        cin >> p1[i] >> p2[i] >> p3[i];
        p2[i]++;
    }
    while (n--) {
        int cl = p1[n], cr = p2[n], t = p3[n];
        int now = 0;
        for (int i = cl; i <= cr; i++) {
            l[i] = min(l[i], cr);
        }
        for (int i = cl; i <= cr; i++) {
            tmp[i] = l[i] - t;
        }
        for (int i = cr; i >= cl; i--) {
            if (i - t >= cl) {
                l[i] = max(tmp[i], l[i - t]);
            } else l[i] = tmp[i];
            if (l[i] >= i) now = 1;
        }
        ok &= now;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
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