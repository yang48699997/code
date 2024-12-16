#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T> 
struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int x) : n(x), a(x + 1) {};
    void build() {
        for (int i = 1; i <= n; i++) {
            int nxt = i + (i & -i);
            if (nxt <= n) a[nxt] += a[i];
        }
    }
    T query(int x) {
        T res = 0;
        while (x) {
            res += a[x];
            x -= (x & -x);
        }
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int x, T val) {
        while (x <= n) {
            a[x] += val;
            x += (x & -x);
        }
        return;
    }
};

using F = Fenwick<ll>;

const int mx = 2e5 + 5;

void solve() {
    int n, M;
    cin >> n >> M;

    vector<ll> a(n);
    F f(mx), f2(mx);
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll p = 0;
    for (int i = n - 1; i >= 0; i--) {
        p = (p + a[i]) % M;
        a[i] -= p;
        a[i] %= M;
        if (a[i] < 0) a[i] += M;
        if (a[i]) {
            f.update(a[i], a[i]);
            f2.update(a[i], 1);
        }
        
        ans += f.query(M) + (n - i) * p;
        ans -= f2.query(M - p, M) * M;
        
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}