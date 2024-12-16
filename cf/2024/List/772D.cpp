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

struct Info {
    Z f0 = 1;
    Z f1 = 0;
    Z f2 = 0;
    const Info operator+(const Info &info) {
        return {
            f0 * info.f0,
            f1 * info.f0 + f0 * info.f1,
            f0 * info.f2 + 2 * f1 * info.f1 + f2 * info.f0
        };
    }
    const Info operator+=(const Info &info) {
        return {
            f0 * info.f0,
            f1 * info.f0 + f0 * info.f1,
            f0 * info.f2 + 2 * f1 * info.f1 + f2 * info.f0
        };
    }
    const Info operator-(const Info &info) {
        return {
            f0 - info.f0,
            f1 - info.f1,
            f2 - info.f2
        };
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Info> f(N);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        Z x = p;
        f[p] = f[p] + Info{2, x, x * x};
    }


    int p = 1;
    for (int j = 0; j < 6; j++) {
        for (int i = 999999; i >= 0; i--) {
            if (i / p % 10 != 9) {
                f[i] = f[i] + f[i + p];
            }
        }
        p *= 10;
    }
    

    for (int i = 1; i < 1e6; i *= 10) {
        for (int j = 0; j < 1e6; j++) {
            if (j / i % 10 != 9) {
                f[j] = f[j] - f[j + i];
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 1e6; i++) {
        ans ^= f[i].f2.val() * i;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}