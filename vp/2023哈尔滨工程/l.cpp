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
    T query2(int l, int r) {
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

using F = Fenwick<int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), cnt(n);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        return b[x1] < b[x2];
    });
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        f[nums[i]] = i + 1;
        p[a[nums[i]]].push_back(nums[i]);
    }

    int ans = 1e9;
    if (cnt[0] >= n / 2 + n % 2) ans = 0;
    for (int k = cnt[0]; k <= n / 2 + n % 2; k++) {
        int l = k - cnt[0];
        int res = 0;
        F f1(n), f2(n);
        for (int j = 1; j < n; j++) {
            for (int pp = 0; pp < cnt[j]; pp++) {
                if (pp + k <= cnt[j]) {
                    res += b[p[j][pp]];
                    l--;
                } else {
                    f1.update(f[p[j][pp]], 1);
                    f2.update(f[p[j][pp]], b[p[j][pp]]);
                }
            }
        }
        if (l <= 0) ans = min(ans, res);
        else {
            int cl = 1, cr = n;
            while (cl <= cr) {
                int mid = (cr + cl) / 2;
                if (f1.query(mid) >= l) cr = mid - 1;
                else cl = mid + 1;
            }
            ans = min(ans, res + f2.query(cl));
        }
        for (int j = 1; j < n; j++) {
            if (cnt[j] < k) continue;
            for (int pp = 0; pp < cnt[j] - k + 1; pp++) {
                res -= b[p[j][pp]];
                l++;
                f1.update(f[p[j][pp]], 1);
                f2.update(f[p[j][pp]], b[p[j][pp]]);
            }
            if (l <= 0) ans = min(ans, res);
            else {
                int cl = 1, cr = n;
                while (cl <= cr) {
                    int mid = (cr + cl) / 2;
                    if (f1.query(mid) >= l) cr = mid - 1;
                    else cl = mid + 1;
                }
                ans = min(ans, res + f2.query(cl));
            }
            for (int pp = 0; pp < cnt[j] - k + 1; pp++) {
                res += b[p[j][pp]];
                l--;
                f1.update(f[p[j][pp]], -1);
                f2.update(f[p[j][pp]], -b[p[j][pp]]);
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