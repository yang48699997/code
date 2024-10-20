#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU{
    vector<ll> fa, sz;
    
    DSU(int n) : fa(n), sz(n, 1) {
        for (int i = 0; i < n; i++) fa[i]=i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
    
    ll size(int x) {
        x = find(x);
        return sz[x];
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> h(n + 1), v(m + 1);  
    vector<int> hh, vv;
    hh.push_back(0);
    hh.push_back(n);
    vv.push_back(0);
    vv.push_back(m);
    h[0].emplace_back(0, m);
    h[n].emplace_back(0, m);
    v[0].emplace_back(0, n);
    v[m].emplace_back(0, n);
    while (q--) {
        int a, p, x;
        cin >> a >> p >> x;
        if (p == 1) {
            int t = max(0, m - a);
            h[x].emplace_back(t, m);
            hh.push_back(x);
        } else if (p == 2) {
            int t = min(m, a);
            h[x].emplace_back(0, t);
            hh.push_back(x);
        } else if (p == 3) {
            int t = min(n, a);
            v[x].emplace_back(0, t);
            vv.push_back(x);
        } else {    
            int t = max(n - a, 0);
            v[x].emplace_back(t, n);
            vv.push_back(x);
        }
    }

    sort(hh.begin(), hh.end());
    hh.erase(unique(hh.begin(), hh.end()), hh.end());
    sort(vv.begin(), vv.end());
    vv.erase(unique(vv.begin(), vv.end()), vv.end());
    ll p1 = hh.size();
    ll p2 = vv.size();
    ll ans = 0;
    DSU dsu((p1 - 1) * (p2 - 1));
    for (int i = 0; i < p2 - 1; i++) {
        for (int j = 0; j < p1 - 1; j++) {
            ll x = vv[i + 1] - vv[i];
            ll y = hh[j + 1] - hh[j];
            dsu.sz[i * (p1 - 1) + j] = x * y;
            ans = max(ans, x * y);
        }
    }


    for (int i = 0; i <= n; i++) {
        int k = h[i].size();
        sort(h[i].begin(), h[i].end());
        vector<pair<int, int>> res;
        for (int j = 0; j < k; ) {
            int l = h[i][j].first;
            int r = h[i][j].second;
            int now = j;
            while (now < k && h[i][now].first <= r) {
                r = max(r, h[i][now].second);
                now++;
            }
            res.emplace_back(l, r);
            j = now;
        }
        h[i] = res;
    } 
    for (int i = 0; i <= m; i++) {
        int k = v[i].size();
        sort(v[i].begin(), v[i].end());
        vector<pair<int, int>> res;
        for (int j = 0; j < k; ) {
            int l = v[i][j].first;
            int r = v[i][j].second;
            int now = j;
            while (now < k && v[i][now].first <= r) {
                r = max(r, v[i][now].second);
                now++;
            }
            res.emplace_back(l, r);
            j = now;
        }
        v[i] = res;
    }

    const int inf = 1e9;
    for (int i = 0; i < p2 - 1; i++) {
        for (int j = 0; j < p1 - 1; j++) {
            int u = vv[i + 1];
            int d = vv[i];
            int r = hh[j + 1];
            int l = hh[j];
            ll now = i * (p1 - 1) + j;
            auto it1 = upper_bound(v[u].begin(), v[u].end(), make_pair(l, inf));
            if (it1 != v[u].begin()) {
                it1--;
                if (it1 -> second < r) {
                    dsu.merge(now, now + p1 - 1);
                    ans = max(ans, dsu.size(now));
                }
            } else {
                dsu.merge(now, now + p1 - 1);
                ans = max(ans, dsu.size(now));
            }
            auto it2 = upper_bound(v[d].begin(), v[d].end(), make_pair(l, inf));
            if (it2 != v[d].begin()) {
                it2--;
                if (it2 -> second < r) {
                    dsu.merge(now, now - p1 + 1);
                    ans = max(ans, dsu.size(now));
                }
            } else {
                dsu.merge(now, now - p1 + 1);
                ans = max(ans, dsu.size(now));
            }
            auto it3 = upper_bound(h[l].begin(), h[l].end(), make_pair(d, inf));
            if (it3 != h[l].begin()) {
                it3--;
                if (it3 -> second < u) {
                    dsu.merge(now, now - 1);
                    ans = max(ans, dsu.size(now));
                }
            } else {
                dsu.merge(now, now - 1);
                ans = max(ans, dsu.size(now));
            }
            auto it4 = upper_bound(h[r].begin(), h[r].end(), make_pair(d, inf));
            if (it4 != h[r].begin()) {
                it4--;
                if (it4 -> second < u) {
                    dsu.merge(now, now + 1);
                    ans = max(ans, dsu.size(now));
                }
            } else {
                dsu.merge(now, now + 1);
                ans = max(ans, dsu.size(now));
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