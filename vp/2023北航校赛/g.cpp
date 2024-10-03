#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m), v(m);
    map<ll, ll> mp;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        v[i] %= k;
        mp[v[i]] += a[i];
    }

    ll ans = 0;
    vector<ll> val, cnt;
    for (auto [vv, c] : mp) {
        val.push_back(vv);
        cnt.push_back(c);
    }
    int l = 0, r = cnt.size() - 1;
    while (l <= r) {
        if (l == r) {
            ans += cnt[l] / 2 * ((val[l] + val[r]) % k);
            l++;
            r--;
        } else {
            if ((val[l] + val[r]) < k) {
                ll pp = min(cnt[l], cnt[r]);
                ans += min(cnt[l], cnt[r]) * (val[l] + val[r]);
                cnt[l] -= pp;
                cnt[r] -= pp;
                if (cnt[l] == 0) l++;
                if (cnt[r] == 0) r--;
            }else {
                ans += cnt[r] / 2 * ((val[r] + val[r]) % k);
                cnt[r] %= 2;
                if (cnt[r]) {
                    cnt[r - 1]--;
                    ans += (val[r - 1] + val[r]) % k;
                }
                r--;
            }
        } 
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}