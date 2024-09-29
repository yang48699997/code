#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU{
    vector<int> fa, sz;
    vector<int> v;
    DSU(int n) : fa(n), sz(n, 1), v(n) {
        for ( int i = 0; i < n; i++) fa[i]=i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        sz[x] += sz[y];
        v[x] |= v[y];
        fa[y] = x;
        return true;
    }
    
    int size(int x) {
        x = find(x);
        return sz[x];
    }

    int vis(int x) {
        return v[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);

    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        return a[x1] > a[x2];
    });
    int cnt = 0;
    int mx = a[nums[0]];
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            dsu.v[i] = 1;
        }
    }
    vector<int> v(n);
    int sum = 0;
    int ans = 0;
    DSU dsu2(n);
    auto merge = [&](int i, int j) -> void {
        if (i < 0 || i >= n || j < 0 || j >= n) return;
        if (!v[i] || !v[j]) return;
        if (dsu.vis(i) == dsu.vis(j)) cnt -= dsu.vis(i);
        dsu.merge(i, j);
        dsu2.merge(i, j);
    };
    for (int i : nums) {
        v[i] = 1;
        cnt += dsu.vis(i);
        sum++;
        if (i > 0 && v[i - 1]) {
            if (dsu2.size(i - 1) % 2 == 0) {
                cnt -= dsu.vis(i - 1);
            } else {
                sum--;
                if (i > 1 && v[i - 2]) cnt += dsu.vis(i - 2);
            }
            merge(i - 2, i);
            dsu2.merge(i, i - 1);
        }
        if (i < n - 1 && v[i + 1]) {
            int sz1 = dsu2.size(i);
            int sz2 = dsu2.size(i + 1);
            dsu2.merge(i, i + 1);
            if (sz1 & 1) {
                if (sz2 & 1) {
                    merge(i, i + 2);
                    if (i > 0 && v[i - 1]) cnt += dsu.vis(i - 1);
                    if (i < n - 2 && v[i + 2]) cnt += dsu.vis(i + 2);
                    merge(i - 1, i + 1);
                    sum--;
                } else {
                    if (i > 0 && v[i - 1]) {
                        cnt += dsu.vis(i - 1);
                        merge(i - 1, i + 1);
                    }
                    cnt -= dsu.vis(i + 1);
                }
            } else if (sz2 & 1) {
                if (i < n - 2 && v[i + 2]) {
                    cnt += dsu.vis(i);
                    merge(i, i + 2);
                }
                cnt -= dsu.vis(i);
            } else {
                merge(i, i + 2);
                merge(i - 1, i + 1);
            }
        }
        int res = mx + a[i] + sum;
        if (cnt == 0) res--;
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}