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
 
constexpr ll P = 1e9 + 7;
using Z = MInt<P>;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    string tt = "^#";
    for (int i = m - 1; i >= 0; i--) {
        tt += t[i];
        tt += '#';
    }
    tt += '?';
    int mm = tt.size();
    int cc = 0, rr = 0;
    vector<int> pp(mm);
    for (int i = 1; i < mm - 1; i++) {
        int i_m = 2 * cc - i;
        if (rr > i) pp[i] = min(pp[i_m], rr - i);
        else pp[i] = 0;
        while (tt[i + 1 + pp[i]] == tt[i - 1 - pp[i]]) pp[i]++;
        if (pp[i] + i > rr) {
            rr = pp[i] + i;
            cc = i;
        }
    }
    // cerr << tt << "\n";
    // for (int i = 0; i < mm; i++) {
    //     cerr << pp[i] << " \n"[i == mm - 1];
    // }
    vector<int> ok(m);
    for (int i = m - 1; i >= 0; i--) {
        int cur = (m - i) * 2;
        int tar = 2;
        if (pp[(cur + tar) / 2] == m - i) ok[i] = 1;
        // cerr << ok[i] << "\n";
    }
    vector<vector<int>> p(26);
    for (int i = 0; i < n; i++) {
        p[s[i] - 'a'].push_back(i);
    }
    int l = -1;
    vector<int> pre(m);
    vector<int> suf(m);
    int cnt = 0;
    for (char c : t) {
        auto it = upper_bound(p[c - 'a'].begin(), p[c - 'a'].end(), l);
        if (it == p[c - 'a'].end()) {
            cout << "0\n";
            return;
        }
        l = *it;
        pre[cnt++] = l;
    }
    int r = n;
    for (int i = 0; i < m; i++) {
        int c = t[i] - 'a';
        auto it = lower_bound(p[c].begin(), p[c].end(), r);
        if (it == p[c].begin()) {
            cout << "0\n";
            return;
        }
        r = *(it - 1);
        suf[i] = r;
    }

    Z ans = 0;
    if (l < r) {
        int len = r - l - 1;
        vector<Z> dp(len + 1);
        vector<int> last(26);
        for (int i = 1; i <= len; i++) {
            int c = s[i + l] - 'a';
            if (!last[c]) {
                dp[i] = dp[i - 1] * 2 + 1;
            } else {
                dp[i] = dp[i - 1] * 2 - dp[last[c] - 1];
            }
            last[c] = i;
        }
        ans = dp[len] + 1;
        int cur = m - 1;
        while (cur >= 0) {
            ans += ok[cur];
            cur--;
        }
        cout << ans << "\n";
    } else {
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i];
            if (s[i] == t.back()) p[i + 1]++;
        }
        int cur = m - 1;
        int mx = pre[m - 1];
        while (cur >= 0) {
            if (!ok[cur]) {
                cur--;
                continue;
            }
            if (suf[cur] >= mx) ans += 1;
            cur--;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}