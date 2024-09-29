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
const int N = 1e6 + 5;
const int mx = 21;
Z dp[N][mx];
Z fac[N], ifac[N];
ll powMod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if(y & 1)res = res * x % P;
        x = x * x % P;
        y >>= 1;
    };
    return res;
};
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < mx; j++) {
            dp[i][j] = 0;
        }
    }
    dp[1][1] = 1;
    for (int i = 2; i < N; i++) {
        dp[i][1] = 1;
        for (int j = mx - 2; j > 0; j--) {
            for (int now = i + i; now < N; now += i) {
                dp[now][j + 1] += dp[i][j];
            }
        }
    }
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i;
        ifac[i] = powMod(fac[i].val(), P - 2);
    }
}
void solve() {
    int x, y;
    cin >> x >> y;
    Z ans = 0;
    if (x == 1) {
        ans = powMod(2, y - 1);
        cout << ans << "\n";
        return;
    }
    for (int i = 1; i <= min(mx - 1, y); i++) {
        ans += dp[x][i] * powMod(2, y - 1) * fac[y] * ifac[i] * ifac[y - i];
    }
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