#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    int p = b.size();
    for (int i = 0; i < b.size(); i++) {
        if (b[i] != i) {
            p = i;
            break;
        }
    }

    int l = n, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == p + 1) {
            l = min(l, i);
            r = max(r, i);
        }
    }

    if (r == -1) {
        if (p == n) cout << "No\n";
        else cout << "Yes\n";
        return;
    }

    vector<int> v(p);
    for (int i = 0; i < n; i++) {
        if (i < l || i > r) {
            if (a[i] < p) v[a[i]] = 1;
        }
    }

    cout << (accumulate(v.begin(), v.end(), 0) == p ? "Yes" : "No") << '\n';

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