#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const int mx = 1e6 + 5;
const int p = 350;

struct fenwich {
    vector<ll> sum;
    vector<ll> sum2;
    vector<int> cnt;
    fenwich() : sum(mx), cnt(mx), sum2(mx) {}
    void build() {
        for (int i = 1; i < mx; i++) {
            int nxt = i + (i & -i);
            if (nxt < mx) {
                sum[nxt] += sum[i];
                cnt[nxt] += cnt[i];
            }
        }
    }
    void update(ll x) {
        int cur = x;
        ll y = x * x;
        while (cur < mx) {
            cnt[cur]++;
            sum[cur] += x;
            sum2[cur] += y;
            cur += (cur & -cur);
        }
    }
    ll get_count(int i) {
        int cur = i;
        ll ans = 0;
        while (cur) {
            ans += cnt[cur];
            cur -= (cur & -cur);
        }
        return ans;
    }
    ll get_sum(int i) {
        int cur = i;
        ll ans = 0;
        while (cur) {
            ans += sum[cur];
            cur -= (cur & -cur);
        }
        return ans;
    }
    ll get_sum2(int i) {
        int cur = i;
        ll ans = 0;
        while (cur) {
            ans += sum2[cur];
            cur -= (cur & -cur);
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }     
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> sz(n);
    vector<ll> sub(n);
    int tot = 0;
    vector<int> v(n);
    vector<int> vv(n);
    for (int i = 0; i < n; i++) vv[i] = i;
    vector<fenwich> f;
    vector<vector<int>> son(n);
    auto dfs = [&](auto &&self, int x, int fa) -> void {
        sz[x]++;
        int cnt  = 0;
        int d = -1;
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            self(self, nxt, x);
            sz[x] += sz[nxt];
            if (sz[nxt] > cnt) {
                cnt = sz[nxt];
                d = nxt;
            }
        }
        if (sz[x] <= p) {
            son[x].push_back(a[x]);
            for (int nxt : e[x]) {
                if (nxt == fa) continue;
                for (ll j : son[nxt]) son[x].push_back(j);
            }
            sort(son[x].begin(), son[x].end());
            int c = 0;
            ll s = 0;
            for (int i = 0; i < sz[x]; i++) {
                c++;
                s += son[x][i];
                sub[x] += 2 * son[x][i] * (son[x][i] * c - s);
            }
        } else if (cnt > p){
            v[x] = v[d];
            vv[x] = vv[d];
            son[vv[x]].push_back(a[x]); 
            sub[x] += sub[d];
            for (int nxt : e[x]) {
                if (nxt == fa || nxt == d) continue;
                for (ll j : son[nxt]) {
                    f[v[x]].update(j);
                    ll c = f[v[x]].get_count(j);
                    ll s = f[v[x]].get_sum(j);
                    sub[x] += j * 2 * (j * c - s);
                    son[vv[x]].push_back(j); 
                    ll c2 = f[v[x]].get_count(mx - 1) - c;
                    ll temp = f[v[x]].get_sum(mx - 1) - s;
                    sub[x] += j * 2 * (c2 * j - temp);
                    ll s2 = f[v[x]].get_sum2(mx - 1) - f[v[x]].get_sum2(j);
                    sub[x] += s2 - j * j * c2;
                    sub[x] += s2 - j * j * c2;
                }
            }
            f[v[x]].update(a[x]);
            ll c = f[v[x]].get_count(a[x]);
            ll s = f[v[x]].get_sum(a[x]);
            sub[x] += a[x] * 2 * (a[x] * c - s);
            ll j = a[x];
            ll c2 = f[v[x]].get_count(mx - 1) - c;
            ll temp = f[v[x]].get_sum(mx - 1) - s;
            sub[x] += j * 2 * (c2 * j - temp);
            ll s2 = f[v[x]].get_sum2(mx - 1) - f[v[x]].get_sum2(j);
            sub[x] += s2 - a[x] * a[x] * c2;
            sub[x] += s2 - a[x] * a[x] * c2;
        } else {
            f.push_back(fenwich{});
            v[x] = tot++;
            f[v[x]].update(a[x]);
            son[x].push_back(a[x]);
            for (int nxt : e[x]) {
                if (nxt == fa) continue;
                for (ll j : son[nxt]) {
                    f[v[x]].update(j);
                    ll c = f[v[x]].get_count(j);
                    ll s = f[v[x]].get_sum(j);
                    sub[x] += j * 2 * (j * c - s);
                    son[x].push_back(j);
                    ll c2 = f[v[x]].get_count(mx - 1) - c;
                    ll temp = f[v[x]].get_sum(mx - 1) - s;
                    sub[x] += j * 2 * (c2 * j - temp);
                    ll s2 = f[v[x]].get_sum2(mx - 1) - f[v[x]].get_sum2(j);
                    sub[x] += s2 - j * j * c2;
                    sub[x] += s2 - j * j * c2;
                }
            }
        }
    };

    dfs(dfs, 0, -1);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        // cerr << i << ": " << sub[i] << "\n"; 
        ans ^= sub[i];
    }
    cout << ans << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}