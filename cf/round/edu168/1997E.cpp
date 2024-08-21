#include <bits/stdc++.h>
using namespace std;

const int N = 100;

struct Fenwick {
    int n;
    vector<int> a;

    Fenwick(int x) : n(x), a(x + 1) {}

    void build() {
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            a[i] += a[i - 1];
        }
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += a[x];
            x -= (x & -x);
        }
        return res;
    }

    int query2(int l, int r) {
        return a[r] - a[l - 1];
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    

    vector<Fenwick> p(N + 1, n);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] >= i) p[i].a[j]++;
        }
        p[i].build();
    }

    vector<int> qx(q), qk(q), nums(q), ans(q);
    for (int i = 0; i < q; i++) {
        cin >> qx[i] >> qk[i];
        nums[i] = i;
    }

    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        return qk[x1] < qk[x2];
    });

    vector<int> ok(n + 1);
    for (int i = 0; i < q; i++) {
        int x = qx[nums[i]];
        int k = qk[nums[i]];
        if (i > 0 && k <= 2000 && k == qk[nums[i - 1]]) {
            if (ok[x]) ans[nums[i]] = 1;
            continue;
        }
        if (k <= 2000) {
            int kn = 0;
            int now = 1;
            for (int j = 1; j <= n; j++) {
                if (a[j] >= now) {
                    kn = (kn + 1) % k;
                    if (kn == 0) now++;
                    ok[j] = 1; 
                } else ok[j] = 0;
            }
            if (ok[x]) ans[nums[i]] = 1;
            continue;
        }
        int l = 1, r = k;
        int now = 1;
        while (r < x) {
            l = r + 1;
            now++;
            r = min(x, r + k);
            int mr = x;
            while (r <= mr) {
                int mid = (mr - r) / 2 + r;
                if (p[now].query2(l, mid) < k) r = mid + 1;
                else mr = mid - 1;
            }
        }
        if (now <= a[x]) ans[nums[i]] = 1;
    }
    for (int i = 0; i < q; i++) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}