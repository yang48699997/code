#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mx = 1e7 + 5;
int v[mx];

void init() {
    for (int i = 0; i < mx; i++) v[i] = 0;
    v[1] = 1;
    int now = 1;
    for (int i = 3; i < mx; i += 2) {
        if (v[i]) continue;
        v[i] = ++now;
        for (int j = i; j < mx; j += i * 2) {
            if (v[j]) continue;
            v[j] = now;
        }
    } 
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans ^= v[a[i]];
    }

    if (ans) cout << "Alice\n";
    else cout << "Bob\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    init();
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}