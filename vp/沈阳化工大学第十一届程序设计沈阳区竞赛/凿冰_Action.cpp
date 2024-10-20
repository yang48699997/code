#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    ll ans1 = 0, ans2 = 0;
    vector<ll> lef;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            ll x;
            cin >> x;
            if (j < m / 2) ans1 += x;
            else if (j == m / 2 && m % 2) lef.push_back(x);
            else ans2 += x;
        }
    }

    sort(lef.rbegin(), lef.rend());
    for (int i = 0; i < lef.size(); i++) {
        if (i & 1) ans2 += lef[i];
        else ans1 += lef[i];
    }

    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}