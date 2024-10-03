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
    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;
    int a;
    cin >> a;
    vector<vector<int>> v(n, vector<int> (10));
    vector<vector<Z>> mp(n, vector<Z> (10));

    auto dfs = [&](auto &&self, int i, int p, int mi, int mx) -> Z {
        int cnt = __builtin_popcount(p);
        if (i == n) {
            if (cnt == a) return 1;
            return 0;
        }
        Z res = 0;
        if (!mi && !mx) {
            if (v[i][cnt]) return mp[i][cnt];
            res += cnt * self(self, i + 1, (1 << cnt) - 1, 0, 0);
            if (cnt < 10) res += (10 - cnt) * self(self, i + 1, (1 << cnt << 1) - 1, 0, 0);
            mp[i][cnt] = res;
            v[i][cnt] = 1;
            return res;
        } else if (mi && mx) {
            for (int j = l[i] - '0'; j <= r[i] - '0'; j++) {
                res += self(self, i + 1, p | 1 << j, j == l[i] - '0', j == r[i] - '0');
            }
        } else if (mi) {
            for (int j = l[i] - '0'; j < 10; j++) {
                res += self(self, i + 1, p | 1 << j, j == l[i] - '0', 0);
            }
        } else {
            for (int j = 0; j <= r[i] - '0'; j++) {
                res += self(self, i + 1, p | 1 << j, 0, j == r[i] - '0');
            }
        }

        return res;
    };
    cout << dfs(dfs, 0, 0, 1, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}