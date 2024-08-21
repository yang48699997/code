#include <bits/stdc++.h>
using namespace std;

using ll = long long;


template<class T>
struct SegmentTree {
    static int n;
    vector<T> a, tr1, tr2, mark;
    SegmentTree(int x) {
        n = x;
        a.resize(x + 1);
        tr1.resize((x + 1) << 2);
        tr2.resize((x + 1) << 2);
        mark.resize((x + 1) << 2);
    }

    void set(int i, T x) {
        a[i] = x;
    }
    void build(int p = 1, int l = 1, int r = n) {
        if (l == r) {
            tr1[p] = a[l];
            tr2[p] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        tr1[p] = max(tr1[p << 1], tr1[p << 1 | 1]);
        tr2[p] = min(tr2[p << 1], tr2[p << 1 | 1]);
    }
    void update(int l, int r, T x, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            tr1[p] = x;
            tr2[p] = x;
            return;
        }
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr1[p] = max(tr1[p << 1], tr1[p << 1 | 1]);
        tr2[p] = min(tr2[p << 1], tr2[p << 1 | 1]);
        return;
    }
    T query1(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr1[p];
        }
        int mid = (cl + cr) / 2;
        T ans = 0;
        if (l <= mid) {
            ans = max(ans, query1(l, r, p << 1, cl, mid));
        }
        if (r > mid) {
            ans = max(ans, query1(l, r, p << 1 | 1, mid + 1, cr));
        }
        return ans;
    }
};

template<class T>
int SegmentTree<T>::n = 0;

using S1 = SegmentTree<ll>;

template<class T>
struct SegmentTree2 {
    static int n;
    vector<T> a, tr1, tr2, mark;
    SegmentTree2(int x) {
        n = x;
        a.resize(x + 1);
        tr1.resize((x + 1) << 2);
        tr2.resize((x + 1) << 2);
        mark.resize((x + 1) << 2);
    }

    void set(int i, T x) {
        a[i] = x;
    }
    void build(int p = 1, int l = 1, int r = n) {
        if (l == r) {
            tr1[p] = a[l];
            tr2[p] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        tr1[p] = max(tr1[p << 1], tr1[p << 1 | 1]);
        tr2[p] = min(tr2[p << 1], tr2[p << 1 | 1]);
    }

    void update(int l, int r, T x, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            tr1[p] = x;
            tr2[p] = x;
            return;
        }
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr1[p] = max(tr1[p << 1], tr1[p << 1 | 1]);
        tr2[p] = min(tr2[p << 1], tr2[p << 1 | 1]);
        return;
    }
    T query2(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr2[p];
        }
        int mid = (cl + cr) / 2;
        T ans = n + 1;
        if (l <= mid) {
            ans = min(ans, query2(l, r, p << 1, cl, mid));
        }
        if (r > mid) {
            ans = min(ans, query2(l, r, p << 1 | 1, mid + 1, cr));
        }
        return ans;
    }
};

template<class T>
int SegmentTree2<T>::n = 0;

using S2 = SegmentTree2<ll>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> cnt(n + 1);
    vector<vector<int>> p(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        p[a[i]].push_back(i + 1);
    }
    int ok = 1;
    vector<int> ans;
    
    vector<int> v(n + 1);
    set<int> st;
    for (int i = n - 1; i >= 0; i--) {
        if (!v[a[i]]) {
            v[a[i]] = 1;
            st.insert(i + 1);
        }
    }
    S1 t1(n);
    S2 t2(n);
    for (int i = 0; i < n; i++) {
        t1.set(i + 1, a[i]);
        t2.set(i + 1, a[i]);
    }
    t1.build();
    t2.build();

    int l = 1;
    while (!st.empty()) {
        int r = *st.begin();
        if (ok) {
            int x = t1.query1(l, r);
            ans.push_back(x);
            ok = 0;
            auto it = lower_bound(p[x].begin(), p[x].end(), l);
            l = *it + 1;
            while (it != p[x].end()) {
                t1.update(*it, *it, 0);
                t2.update(*it, *it, n + 1);
                st.erase(*it);
                it++;
            }
        } else {
            int x = t2.query2(l, r);
            ans.push_back(x);
            ok = 1;
            auto it = lower_bound(p[x].begin(), p[x].end(), l);
            l = *it + 1;
            while (it != p[x].end()) {
                t1.update(*it, *it, 0);
                t2.update(*it, *it, n + 1);
                st.erase(*it);
                it++;
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
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