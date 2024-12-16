#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> v(n); 
    for (int i = 0; i < n; i++) cin >> v[i][0];
    for (int i = 0; i < n; i++) cin >> v[i][1];

    map<int, ll> cnt;
    const int inf = -1e9 - 1;
    cnt[inf] = 0;
    for (int i = 0; i < n; i++) {
        int x = v[i][0];
        int p = v[i][1];
        cnt[x] += p;
    }

    vector<int> p;
    vector<ll> pre(1);
    for (auto [x, c] : cnt) {
        p.push_back(x);
        pre.push_back(pre.back() + c);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it = upper_bound(p.begin(), p.end(), r);
        it--;
        int cr = it - p.begin();
        ll ans = pre[cr + 1];

        it = lower_bound(p.begin(), p.end(), l);
        int cl = it - p.begin();
        ans -= pre[cl];

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}