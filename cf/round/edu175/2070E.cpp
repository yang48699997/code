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

void solve() {
    int n;
    string s;
    cin >> n >> s;

    
    if (count(s.begin(), s.end(), '1') == n) {
        cout << "0\n";
        return;
    } else if (count(s.begin(), s.end(), '0') == n) {
        cout << 1LL * n * (n - 1) / 2 << "\n";
        return;
    }

    int N = 3 * n;
    ll ans = 0;
    ll p = N;
    F f(n * 4);
    vector<F> ff(4, n * 4);
    
    f.update(p, 1);
    ff[3].update(p, 1);

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') p++;
        else p -= 3;

        int pre = ((i + 1) & 3);

        ans += f.query(1, p - 2) + ff[pre].query(p - 1, p + 1);

        f.update(p, 1);
        ff[i & 3].update(p, 1);

    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}