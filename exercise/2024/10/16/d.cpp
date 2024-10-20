#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mx = 4e4;
int p[mx];
int tot;

void init() {
    tot = 0;
    vector<int> v(mx);
    for (int i = 2; i < mx; i++) {
        if (!v[i]) {
            p[tot++] = i; 
        }
        for (int j = 0; p[j] * i < mx; j++) {
            v[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<array<int, 2>>> v(n);
    map<int, vector<int>> mp; 
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int now = a[i];
        int x = 1;
        for (int j = 0; j < tot && p[j] <= now; j++) {
            if (now % p[j]) continue;
            int cnt = 0;
            while (now % p[j] == 0) {
                cnt++;
                now /= p[j];
            }
            if (cnt % 3 == 0) continue;
            v[i].push_back({p[j], cnt});
            x *= p[j];
        }
        if (now > 1) {
            v[i].push_back({now, 1});
            x *= now;
        }
        mp[x].push_back(i);
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        auto t = it -> second;
        map<ll, ll> cnt;
        for (int i = 0; i < t.size(); i++) {
            ll now = 0;
            for (int j = 0; j < v[t[i]].size(); j++) {
                if (v[t[i]][j][1] % 3 == 0) continue;
                else if (v[t[i]][j][1] % 3 == 1) now |= (1LL << j << j);
                else now |= (3LL << j << j);
            }
            ans += cnt[now]++;            
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}