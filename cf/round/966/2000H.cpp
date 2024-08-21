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
        tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
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
        tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
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
            ans = max(ans, query(l, r, p << 1, cl, mid));
        }
        if (r > mid) {
            ans = max(ans, query(l, r, p << 1 | 1, mid + 1, cr));
        }
        return ans;
    }
};

template<class T>
int SegmentTree<T>::n = 0;

using S = SegmentTree<ll>;
const int mx = 2e6 + 1;
void solve() {
    int n;
    cin >> n;
    int tot = 0;
    vector<int> p(1);
    vector<int> a(n);
    map<int, int> mp;
    set<int> st;
    st.insert(1);
    st.insert(mx);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
        st.insert(a[i] + 1);
    }
    int m;
    cin >> m;
    vector<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        char c;
        int x;
        cin >> c >> x;
        q.push_back({c, x});
        if (c == '+') {
            st.insert(x);
            st.insert(x + 1);
        }
    }
    for (auto x : st) {
        mp[x] = ++tot;
        p.push_back(x);
    }
    S t(tot);
    st = set<int> ();
    t.set(1, mx);
    t.set(tot, mx);
    t.build();
    st.insert(0);
    st.insert(mx * 2);
    for (int i = 0; i < n; i++) {
        auto it = st.upper_bound(a[i]);
        int r = *it;
        int l = *--it;
        st.insert(a[i]);
        t.update(mp[l + 1], mp[l + 1], a[i] - l - 1);
        t.update(mp[a[i] + 1], mp[a[i] + 1], r - a[i] - 1);
    }

    for (auto [c, x] : q) {
        m--;
        if (c == '+') {
            auto it = st.upper_bound(x);
            int r = *it;
            int l = *--it;
            st.insert(x);
            t.update(mp[l + 1], mp[l + 1], x - l - 1);
            t.update(mp[x + 1], mp[x + 1], r - x - 1);
        } else if (c == '-') {
            st.erase(x);
            auto it = st.lower_bound(x);
            int r = *it;
            int l = *--it;
            t.update(mp[l + 1], mp[l + 1], r - l - 1);
            t.update(mp[x + 1], mp[x + 1], 0);
        } else {
            int l = 1, r = tot;
            while (l <= r) {
                int mid = (l + r) / 2;
                int res = t.query(1, mid);
                if (res >= x) r = mid - 1;
                else l = mid + 1;
            }
            cout << p[l] << " ";
        }
    }
    cout << "\n";
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