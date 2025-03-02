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
    int n, m;
    cin >> n >> m;

    vector<int> a, b, c;
    for (int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 0) a.push_back(x);
        else if (t == 1) b.push_back(x);
        else c.push_back(x); 
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.rbegin(), c.rend());

    vector<int> p = a;
    for (int i = 0; i < b.size(); i++) p.push_back(b[i]);

    if (p.empty()) {
        cout << "0\n";
        return;
    }

    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int N = p.size();
    map<int, int> ref;
    for (int i = 0; i < N; i++) {
        ref[p[i]] = i + 1;
    }

    F f1(N), f2(N);
    for (int i = 0; i < a.size(); i++) {
        int x = a[i];
        int pos = ref[a[i]];

        f1.update(pos, 1);
        f2.update(pos, x);
    }

    auto cal = [&]() -> ll {
        ll res = 0;
        int l = 1, r = N;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (f1.query(mid, N) <= m) r = mid - 1;
            else l = mid + 1;
        }
        int cnt = f1.query(l, N);
        cnt -= m;
        cnt = max(cnt, 0);
        return f2.query(l, N) - 1LL * cnt * p[l - 1];
    };

    ll ans = cal();

    for (int i = 0; i < c.size(); i++) {
        m--;
        if (m == 0) break;
        int x = c[i];
        while (!b.empty() && x) {
            x--;
            int pos = ref[b.back()];
            f1.update(pos, 1);
            f2.update(pos, b.back());
            b.pop_back();
        }     
        ans = max(ans, cal());   
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}