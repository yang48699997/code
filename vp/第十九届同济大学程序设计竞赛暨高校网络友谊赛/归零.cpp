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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    F f1(n), f2(n), f3(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f1.update(i + 1, a[i]);
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) nums[i] = i;
    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        return a[x1] < a[x2];
    });

    vector<array<int, 3>> ask(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i][0] >> ask[i][1] >> ask[i][2];
    }
    vector<int> query(q);
    for (int i = 0; i < q; i++) query[i] = i;
    sort(query.begin(), query.end(), [&](int x1, int x2){
        return ask[x1][2] < ask[x2][2];
    });

    int l = 0;
    vector<ll> ans(q);
    for (auto p : query) {
        int k = ask[p][2];
        int cl = ask[p][0];
        int cr = ask[p][1];
        while (l < n && a[nums[l]] * 2 < k) {
            f2.update(nums[l] + 1, a[nums[l]]);
            f3.update(nums[l] + 1, 1);
            l++;
        }
        ans[p] = 1LL * k * (cr - cl + 1 - f3.query(cl, cr)) + 2 * f2.query(cl, cr) - f1.query(cl, cr);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}