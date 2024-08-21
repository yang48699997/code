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


const int mx = 2e5 + 5;
Z fac[mx];
void init() {
    fac[0] = 1;
    for (int i = 1; i < mx; i++) {
        fac[i] = fac[i - 1] * i;
    }
}

Z powM(Z x, int p) {
    Z res = 1;
    while (p) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

Z comb(int x, int y) {
    return fac[x] * powM(fac[y], P - 2) * powM(fac[x - y], P - 2);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> e(n);
    vector<vector<Z>> dp(n, vector<Z> (2));
    for (int i = 1; i < n; i++) {
        int fa;
        cin >> fa;
        fa--;
        e[fa].push_back(i);
    }

    auto dfs = [&](auto &&self, int x) -> void {
        if (e[x].size() == 0) {
            dp[x][1] = 1;
            return;
        }
        int tot = 0;
        Z p1 = 1;
        Z p2 = 1;
        for (int nxt : e[x]) {
            self(self, nxt);
            if (dp[nxt][1] != 0) tot++;
            if (dp[nxt][0] != 0) p1 *= dp[nxt][0];
            else p2 *= dp[nxt][1];
        }
        if (tot & 1) {
            dp[x][0] = comb(tot, tot / 2) * 2 * p2 * p1;
        } else {
            dp[x][1] = comb(tot, tot / 2) * p1 * p2;
            if (tot > 0) dp[x][1] += comb(tot, tot / 2 - 1) * p1 * p2;
        }
        return;
    };

    dfs(dfs, 0);
    Z ans = powM(dp[0][0] + dp[0][1] * 2, k);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}