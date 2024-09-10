#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T>
struct SegmentTree {
    static int n;
    vector<T> a, tr, mark;
    SegmentTree(int x) {
        n = x;
        a.resize(x + 1);
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
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
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
            int len = cr - cl + 1;
            tr[p] += len * x;
            mark[p] += x;
            return;
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
        return;
    }
    T query(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr[p];
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        T ans = 0;
        if (l <= mid) {
            ans += query(l, r, p << 1, cl, mid);
        }
        if (r > mid) {
            ans += query(l, r, p << 1 | 1, mid + 1, cr);
        }
        return ans;
    }
};

template<class T>
int SegmentTree<T>::n = 0;

using S = SegmentTree<ll>;

struct Node{
    int l;
    int r;
    ll val;
    Node(int l_, int r_, int val_) : l(l_), r(r_), val(val_) {} 
};

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    S t(n - k + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int, int>> ask;  
    vector<int> nums(q);
    iota(nums.begin(), nums.end(), 0);
    vector<ll> ans(q);
    while (q--) {
       int l, r;
       cin >> l >> r;
       ask.emplace_back(l, r); 
    }
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        return ask[x1].first > ask[x2].first;
    });
    vector<int> cnt(n * 2 + 1);
    vector<int> f(k + 1);
    int mx = 0;
    t.build();
    for (int i = n; i > n - k; i--) {
        if (cnt[a[i] - i + n]) f[cnt[a[i] - i + n]]--;
        cnt[a[i] - i + n]++;
        f[cnt[a[i] - i + n]]++;
        mx = max(mx, cnt[a[i] - i + n]);
    }
    stack<Node> stk;
    stk.emplace(n - k + 1, n - k + 1, k - mx);
    t.update(n - k + 1, n - k + 1, k - mx);
    int cl = n - k + 1;
    for (int p : nums) {
        int l = ask[p].first, r = ask[p].second;
        while (cl > l) {
            cl--;
            f[cnt[a[cl + k] - cl - k + n]]--;
            cnt[a[cl + k] - cl - k + n]--;
            f[cnt[a[cl + k] - cl - k + n]]++;
            if (cnt[a[cl] - cl + n]) f[cnt[a[cl] - cl + n]]--;
            cnt[a[cl] - cl + n]++;
            mx = max(mx, cnt[a[cl] - cl + n]);
            f[cnt[a[cl] - cl + n]]++;
            if (!f[mx]) mx--;
            ll val = k - mx;
            int cr = cl;
            t.update(cl, cl, val);
            while (!stk.empty() && val <= stk.top().val) {
                t.update(cr + 1, stk.top().r, val - stk.top().val);
                cr = stk.top().r;
                stk.pop();
            } 
            stk.emplace(cl, cr, val);
        }
        ans[p] = t.query(l, r - k + 1);
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
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