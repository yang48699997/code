#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m + 1);
    v[0] = 1;
    vector<ll> aa(n), bb(n);
    for (int i = 0; i < n; i++) cin >> aa[i];
    for (int i = 0; i < n; i++) cin >> bb[i];
    for (int i = 0; i < n; i++) {
        ll a = aa[i], b = bb[i];
        if (a == 0) continue;
        for (int j = 0; j < 20; j++) {
            if ((1 << j) <= b) {
                b -= (1 << j);
                ll p = (1 << j) * a;
                for (int k = m; k >= p; k--) v[k] |= v[k - p];
            }   
        }
        if (b > 0) {
            ll p = b * a;
            for (int k = m; k >= p; k--) v[k] |= v[k - p];
        }
    } 
    int cnt = count(v.begin(), v.end(), 1) - 1;
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}