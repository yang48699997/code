#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> p = a;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        if (a[i] == p.back()) {
            cout << p[0] << " \n"[i == n - 1];
        } else {
            cout << *upper_bound(p.begin(), p.end(), a[i]) << " \n"[i == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}