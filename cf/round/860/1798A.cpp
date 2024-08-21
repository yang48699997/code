#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int ok = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    if (a.back() == *max_element(a.begin(), a.end()) && b.back() == *max_element(b.begin(), b.end())) ok = 1;
    if (ok) cout << "Yes\n";
    else cout << "No\n";
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