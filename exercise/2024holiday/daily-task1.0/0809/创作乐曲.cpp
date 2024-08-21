#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct SegmentTree {
    static int n;
    vector<T> a, tr, mark;
    SegmentTree(int x) {
        n = x;
        a.resize(x + 1, 100000);
        tr.resize((x + 1) << 2);
        mark.resize((x + 1) << 2);
    }

    void set(int i, T x) {
        a[i] = x;
    }
    void build(int p = 1, int l = 1, int r = n) {
        if (l == r) {
            tr[p] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        tr[p] = min(tr[p << 1], tr[p << 1 | 1]);
    }
    void push_down(int p, int l, int r) {
        int len = r - l + 1;
        tr[p << 1] += (len + 1) / 2 * mark[p];
        tr[p << 1 | 1] += len / 2 * mark[p];
        mark[p << 1] += mark[p];
        mark[p << 1 | 1] += mark[p];
        mark[p] = 0;
        return;
    }
    void update(int l, int r, T x, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            tr[p] = x;
            return;
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr[p] = min(tr[p << 1], tr[p << 1 | 1]);
        return;
    }
    T query(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr[p];
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        T ans = 1000000;
        if (l <= mid) {
            ans = min(ans, query(l, r, p << 1, cl, mid));
        }
        if (r > mid) {
            ans = min(ans, query(l, r, p << 1 | 1, mid + 1, cr));
        }
        return ans;
    }
};

template<class T>
int SegmentTree<T>::n = 0;

using S = SegmentTree<ll>;
const int mx = 1e6;
void solve() {
    int n;
    ll m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int q;
    cin >> q;
    vector<int> nums = a;
    map<int, int> mp;
    int tot = 0;
    sort(nums.begin(), nums.end());
    int mm = unique(nums.begin(), nums.end()) - nums.begin();
    nums.resize(mm);
    for (int i = 0; i < mm; i++) {
        mp[nums[i]] = ++tot;
    }
    S s(mm);
    vector<int> nxt(n);
    nxt[n - 1] = mx;
    s.set(mp[a[n - 1]], n - 1);
    s.build();
    for (int i = n - 2; i >= 0; i--) {
        int r = upper_bound(nums.begin(), nums.end(), a[i] + k) - nums.begin();
        int l = upper_bound(nums.begin(), nums.end(), a[i] - k) - nums.begin() + 1;
        nxt[i] = s.query(l, r);
        s.update(mp[a[i]], mp[a[i]], i);
        // cerr << i << " " << l << " " << r << "\n";
    }
    for (int i = 0; i < n; i++) {
        cerr << nxt[i] << " \n"[i == n - 1];
    }


    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ans = 1;
        vector<int> dp(n);
        dp[l] = 1;
        int len = r - l + 1;
        for (int i = l; i <= r; i++) {
            if (i != l) dp[i] = max(dp[i - 1], dp[i]);
            if (nxt[i] <= r) {
                dp[nxt[i]] = max(dp[nxt[i]], dp[i] + 1);
            }
            ans = max(ans, dp[i]);
            cerr << dp[i] << " \n"[i == r];
        }
        cout << len - ans << "\n";
    }

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