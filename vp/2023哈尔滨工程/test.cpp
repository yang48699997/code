#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;


void solve() {
    int l = 1, r = 10;
    ll ans = 0;
    vector<ll> power(11);
    power[1] = 1;
    for (int i = 2; i <= 10; i++) {
        ll res = i;
        int k = 2;
        while (k--) res = res * i;
        power[i] = res;
        if (i < 10) ans += res;
    }
    vector<ll> p(8);
    auto dfs = [&](auto &&self, int i, ll pre) -> void {
        if (i == 8) {
            if (pre == ans) {
                cout << 1 << " ";
                for (int j = 0; j < 8; j++) {
                    cout << p[j] << " ";
                }
                cout << 10 << "\n";
            }
            return;
        }
        for (ll j = 1; j <= 10; j++) {
            p[i] = j;
            self(self, i + 1, pre + power[j]);
        }
    };

    dfs(dfs, 0, 0);
    vector<ll> q{1, 1, 1, 1, 1, 1, 8, 8, 10, 10};
    ll qq = 0;
    for (int i = 1; i < 9; i++) {
        qq += power[q[i]];
        cerr << power[i] << "\n";
    }
    cout << qq << " " << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}