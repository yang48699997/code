#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sum = 0;
    int tot = 0;
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) tot++;
        pre[i + 1] = pre[i] + a[i];
        sum += a[i];
    }

    if (sum % 3) {
        cout << 0 << "\n";
        return;
    }

    sum /= 3;

    ll ans = 0;
    
    F f(n);
    int p = 0;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > 0) p++;
        if (pre[i] == sum) {
            if (p == 0) continue;
            f.update(p, 1);
        } else if (pre[i] == 2 * sum) {
            if (p == 0 || p == tot) continue;
            ans += f.query(p - 1);
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