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
const int MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    int m;
    cin >> m;

    Z ans = 0;
    vector<ll> cnt(1024);
    ll mask = 1e10;
    auto dfs = [&](auto &&self, int i, ll x) -> void {
        if (i == 10) {
            cnt[x % 1024] += 1;
            cnt[x % 1024] %= MOD;
            return;
        }
        for (int j = 0; j < 10; j++) {
            if (j == 1 || j == 2 || j == 4) continue;
            self(self, i + 1, x * 10 + j);
        }
    };

    dfs(dfs, 0, 0);

    ll p = 0;
    auto dfs2 = [&](auto &&self, int i, ll x) -> void {
        if (i == 7) {
            if (x <= n / mask) p++;
            return;
        }
        for (int j = 0; j < 10; j++) {
            if (j == 1 || j == 2 || j == 4) continue;
            self(self, i + 1, x * 10 + j);
        }
    };

    dfs2(dfs2, 0, 0);

    auto cal = [](ll x, int y) -> Z {
        Z res = 1;
        for (int i = 1; i <= y; i++) {
            res = res * (x - i + 1);
        }
        return res;
    };
    for (int i = 0; i < 1024; i++) {
        cnt[i] *= (p - 1);
        cnt[i] %= MOD;
    }
    cnt[0] = (cnt[0] + MOD - 1) % MOD;

    auto dfs3 = [&](auto &&self, int i, ll x) -> void {
        if (i == 10) {
            if (x > n % mask) return;
            cnt[x % 1024] += 1;
            cnt[x % 1024] %= MOD;
            return;
        }
        for (int j = 0; j < 10; j++) {
            if (j == 1 || j == 2 || j == 4) continue;
            self(self, i + 1, x * 10 + j);
        }
    };

    dfs3(dfs3, 0, 0);

    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            int t = (m + 1024) - (i + j) % 1024;
            t %= 1024;
            if (i == j) {
                if (i == t) {
                    ans += cal(cnt[i], 3); 
                } else {
                    ans += cal(cnt[i], 2) * cal(cnt[t], 1);
                }
            } else if (i == t) {
                ans += cal(cnt[i], 2) * cal(cnt[j], 1);
            } else {
                if (j == t) {
                    ans += cal(cnt[i], 1) * cal(cnt[j], 2);
                } else {
                    ans += cnt[i] * cnt[j] % MOD * cnt[t];
                }
            }
        }
    }
    
    ans /= 6;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}