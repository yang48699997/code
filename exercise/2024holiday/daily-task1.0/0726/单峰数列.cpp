#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwich {
    vector<int> a;
    int n;
    Fenwich(int x) : a(x + 1), n(x){}

    void update(int i, int p) {
        int cur = i;
        while (cur <= n) {
            a[cur] += p;
            cur += (cur & -cur);
        }
    }

    int query(int i) {
        int res = 0;
        while (i) {
            res += a[i];
            i -= (i & -i);
        }
        return res;
    }

    int query2(int l, int r) {
        return query(r) - query(l - 1);
    }

    void build() {
        for (int i = 1; i <= n; i++) {
            int nxt = i + (i & -i);
            if (nxt <= n) a[nxt] += a[i];
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
    }
    for (int i = n; i > 0; i--) {
        a[i] -= a[i - 1];
    }
    vector<Fenwich> f(3, n);
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            f[0].a[i] = 1;
        } else if (a[i] == 0) {
            f[1].a[i] = 1;
        } else {
            f[2].a[i] = 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        f[i].build();
    }

    int q;
    cin >> q;
    int c, l, r, x;
    auto update = [&] (int l, int x) -> void {
        if (l > n) return;
        if (a[l] < 0) {
            a[l] += x;
            if(a[l] == 0) {
                f[0].update(l, -1);
                f[1].update(l, 1);
            }
            else if (a[l] > 0) {
                f[0].update(l, -1);
                f[2].update(l, 1);
            }
        } else if (a[l] == 0) {
            a[l] += x;
            if (a[l] > 0) {
                f[1].update(l, -1);
                f[2].update(l, 1);
            } else if (a[l] < 0) {
                f[1].update(l, -1);
                f[0].update(l, 1);
            }
        } else {
            a[l] += x;
            if (a[l] == 0) {
                f[2].update(l, -1);
                f[1].update(l, 1);
            } else if (a[l] < 0) {
                f[2].update(l, -1);
                f[0].update(l, 1);
            }
        }
    };
    while (q--) {

        cin >> c >> l >> r;
        if (c == 1) {
            cin >> x;
            update(l, x);
            update(r + 1, -x);
        } else if (c == 2) {
            if (l == r) {
                cout << 1 << "\n";
                continue;
            }
            int res = f[1].query2(l + 1, r);
            if (res == r - l) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (c == 3) {
            if (l == r) {
                cout << 1 << "\n";
                continue;
            }
            int res = f[2].query2(l + 1, r);
            if (res == r - l) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (c == 4) {
            if (l == r) {
                cout << 1 << "\n";
                continue;
            }
            int res = f[0].query2(l + 1, r);
            if (res == r - l) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else {
            int cl = l + 1, cr = r - 1;
            while (cl <= cr) {
                int mid = (cr - cl) / 2 + cl;
                if (f[2].query2(l + 1, mid) == mid - l) {
                    cl = mid + 1;
                } else cr = mid - 1;
            }
            cl--;
            if (cl == l || cl == r) {
                cout << 0 << "\n";
            } else {
                int res = f[0].query2(cl + 1, r);
                if (res == r - cl) cout << 1 << "\n";
                else cout << 0 << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}