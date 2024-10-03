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
 
Z pp = 0;
struct Node{
    int fa, len, ok;
    Z cnt;
    map<int, int> nxt;
    Node() {
        nxt.clear();
        fa = 0;
        len = 0;
        ok = 0;
        cnt = 1;
    }
};

template<class T>
struct SAM{
    const int N = 1e6+5;
    int cnt, last;
    vector<vector<int>> e;
    ll sum;
    vector<T> sam;
    SAM(int n) : sam(2 * n), e(2 * n) {
        cnt = 1;
        last = 1;
        sum = 0;
    }
    SAM() : sam(N) {
        cnt = 1;
        last = 1;
        sum = 0;
    }
    void insert(int ch) {
        int cur = ++cnt;
        sam[cnt].len = sam[last].len + 1;
        int p = last;
        for (; p && !sam[p].nxt[ch]; p = sam[p].fa) sam[p].nxt[ch] = cur;
        int q = sam[p].nxt[ch];
        if (q == 0) {
            sam[cur].fa = 1;
        } else if (sam[q].len == sam[p].len + 1) {
            sam[cur].fa = q;
        } else {
            int r = ++cnt;
            sam[r] = sam[q];
            sam[r].len = sam[p].len + 1;
            sam[cur].fa = sam[q].fa = r;
            for (; p && sam[p].nxt[ch] == q; p = sam[p].fa) sam[p].nxt[ch] = r;
        }
        e[sam[cur]].fa.push_back(cur);
        last = cur;
    }
    void build() {

    }
    ll count() {
        return sum;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];   
    
    Z ans = n;
    p = 0;
    ans *= n;
    SAM<Node> sam(n);
    for (int i = 0; i < n; i++) sam.inser(a[i]);

    sam.build();
    ans -= pp;
    ans /= 2;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}