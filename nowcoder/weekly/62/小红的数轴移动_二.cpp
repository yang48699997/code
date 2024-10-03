#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    x = abs(x);
    const int mx = n * 100;
    vector<int> v(mx + 1);
    v[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p;
        ans += p;
        cin >> p;
        for (int j = mx; j >= p; j--) {
            v[j] |= v[j - p];
        }
    }
    for (int i = x; i <)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}