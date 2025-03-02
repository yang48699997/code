#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T>
constexpr T power(T a, ll b) {
    T res {1};
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
 
constexpr ll mul(ll a, ll b, ll p) {
    ll res = a * b - ll(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
 
template<ll P>
struct MInt {
    ll x;
    constexpr MInt() : x {0} {}
    constexpr MInt(ll x) : x {norm(x % getMod())} {}
    
    static ll Mod;
    constexpr static ll getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(ll Mod_) {
        Mod = Mod_;
    }
    constexpr ll norm(ll x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr ll val() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        if (getMod() < (1ULL << 31)) {
            x = x * rhs.x % int(getMod());
        } else {
            x = mul(x, rhs.x, getMod());
        }
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        ll v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
    friend constexpr bool operator<(MInt lhs, MInt rhs) {
        return lhs.val() < rhs.val();
    }
};
 
template<>
ll MInt<0>::Mod = 998244353;
 
constexpr ll P = 998244353;
using Z = MInt<P>;

template<class Info, class Tag>
struct SegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector<Info>(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void set(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            set(2 * p, l, m, x, v);
        } else {
            set(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void set(int p, const Info &v) {
        set(1, 0, n, p, v);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }
    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
    void update(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        update(2 * p, l, m, x, y, v);
        update(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void update(int l, int r, const Tag &v) {
        return update(1, 0, n, l, r, v);    
    }
};

struct Tag {
    int add = 0;
    void apply(Tag t) {}
};

struct Info {
    Z dp00 = 0;
    Z dp01 = 0;
    Z dp10 = 0;
    Z dp11 = 0;
    Z cnt00 = 0;
    Z cnt01 = 0;
    Z cnt10 = 0;
    Z cnt11 = 0;
    void apply(Tag t) {}
};

Info operator+(const Info &a, const Info &b) {
    Z dp00 = a.dp00 * b.cnt10 + b.dp10 * a.cnt00 + a.dp00 * b.cnt00 + a.cnt00 * b.dp00 - a.cnt00 * b.cnt00;
    dp00 += a.dp01 * b.cnt00 + a.cnt01 * b.dp00 + a.dp01 * b.cnt10 + a.cnt01 * b.dp10 - a.cnt01 * b.cnt10;
    dp00 += a.dp00 + b.dp00;
    Z dp01 = a.dp00 * b.cnt11 + b.dp11 * a.cnt00 + a.dp00 * b.cnt01 + a.cnt00 * b.dp01 - a.cnt00 * b.cnt01;
    dp01 += a.dp01 * b.cnt01 + a.cnt01 * b.dp01 + a.dp01 * b.cnt11 + a.cnt01 * b.dp11 - a.cnt01 * b.cnt11;
    dp01 += a.dp01 + b.dp01;
    Z dp10 = a.dp10 * b.cnt10 + b.dp10 * a.cnt10 + a.dp10 * b.cnt00 + a.cnt10 * b.dp00 - a.cnt10 * b.cnt00;
    dp10 += a.dp11 * b.cnt00 + a.cnt11 * b.dp00 + a.dp11 * b.cnt10 + a.cnt11 * b.dp10 - a.cnt11 * b.cnt10;
    dp10 += a.dp10 + b.dp10;
    Z dp11 = a.dp10 * b.cnt11 + b.dp11 * a.cnt10 + a.dp10 * b.cnt01 + a.cnt10 * b.dp01 - a.cnt10 * b.cnt01;
    dp11 += a.dp11 * b.cnt01 + a.cnt11 * b.dp01 + a.dp11 * b.cnt11 + a.cnt11 * b.dp11 - a.cnt11 * b.cnt11;
    dp11 += a.dp11 + b.dp11;
    Z cnt00 = a.cnt00 * b.cnt00 + a.cnt00 * b.cnt10 + a.cnt01 * b.cnt00 + a.cnt01 * b.cnt10 + a.cnt00 + b.cnt00;
    Z cnt01 = a.cnt00 * b.cnt01 + a.cnt00 * b.cnt11 + a.cnt01 * b.cnt01 + a.cnt01 * b.cnt11 + a.cnt01 + b.cnt01;
    Z cnt10 = a.cnt10 * b.cnt00 + a.cnt10 * b.cnt10 + a.cnt11 * b.cnt00 + a.cnt11 * b.cnt10 + a.cnt10 + b.cnt10;
    Z cnt11 = a.cnt10 * b.cnt01 + a.cnt10 * b.cnt11 + a.cnt11 * b.cnt01 + a.cnt11 * b.cnt11 + a.cnt11 + b.cnt11;
    return {dp00, dp01, dp10, dp11, cnt00, cnt01, cnt10, cnt11};
}

using S = SegmentTree<Info, Tag>;

void solve() {
    string s;
    int q;
    cin >> s >> q;

    int n = s.size();
    S t(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            t.set(i, {1, 0, 0, 0, 1, 0, 0, 0});
        } else {
            t.set(i, {0, 0, 0, 1, 0, 0, 0, 1});
        }
    }

    while (q--) {
        int p;
        cin >> p;
        p--;

        if (s[p] == '0') {
            t.set(p, {0, 0, 0, 1, 0, 0, 0, 1});
            s[p] = '1';
        } else {
            t.set(p, {1, 0, 0, 0, 1, 0, 0, 0});
            s[p] = '0';
        }

        auto res = t.query(0, n);

        cout << res.dp00 + res.dp01 + res.dp10 + res.dp11 << " \n"[q == 0];
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