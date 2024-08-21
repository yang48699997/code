#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
    while (y) {
        int t = y;
        y = x % y;
        x = t;
    };
    return x;
};

int T;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll inf = 2e9;
    ll g = 1;
    for (int i = 0; i < n; i++) {
        ll p = gcd(g, a[i]);
        g = g / p * a[i];
        if (g > inf) {
            cout << n << "\n";
            return;
        }
    }
    if (g != a.back()) {
        cout << n << "\n";
        return;
    }
    vector<pair<int,int>> fac;
    int p = a[n - 1];
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i != 0) continue;
        int cnt = 0;
        while (p % i == 0) {
            cnt++;
            p /= i;
        }
        fac.push_back({i, cnt});
    }
    if (p > 1) fac.push_back({p, 1});
    int m = fac.size();
    set<ll> st(a.begin(), a.end());
    auto dfs = [&](auto &&self, int i, int cur) -> int {
        if (i == m) {
            ll res = 1;
            int ans = 0;
            for (int j = 0; j < n; j++) {
                if (cur % a[j] == 0) {
                    res = res / gcd(res, a[j]) *a[j];
                    ans++;
                }
            }
            if (st.count(res)) return 0;
            else return ans;            
        }
        int ans = 0;
        ans = max(ans, self(self, i + 1, cur));
        for(int j = 0; j < fac[i].second; j++) {
            cur *= fac[i].first;
            ans = max(ans, self(self, i + 1, cur));
        }
        return ans;
    };
    cout << dfs(dfs, 0, 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}