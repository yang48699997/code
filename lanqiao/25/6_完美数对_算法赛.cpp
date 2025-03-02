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
    cin >> n;

    int N = 1e6 + 5;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    vector<int> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    ll ans = 0;

    F f(N + 1);
    priority_queue<array<int, 2>> q;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 0) continue;
        q.push({-cnt[i], i});
        f.update(i, 1);
    }

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 0) continue;
        while (!q.empty() && -q.top()[0] < i) {
            auto [c, x] = q.top();
            q.pop();
            f.update(x, -1);
        }
        ans += f.query(1, cnt[i]);
    }

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}