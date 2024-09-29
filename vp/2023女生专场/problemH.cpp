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
 
constexpr ll P = ll(1E18) + 9;
using Z = MInt<P>;
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const Z B = rng();

void solve() {
    int n, m;
    cin >> n >> m;
    int maxLen = 0;
    vector<string> s(n), t(m);
    for (int i = 0; i < n; i++) cin >> s[i], maxLen = max(maxLen, (int)s[i].size());
    for (int i = 0; i < m; i++) cin >> t[i], maxLen = max(maxLen, (int)s[i].size());

    map<int, unordered_set<ll>> st;
    vector<Z> power(maxLen);
    power[0] = 1;
    for (int i = 1; i < maxLen; i++) power[i] = power[i - 1] * B;
    for (int i = 0; i < n; i++) {
        Z p = 0;
        for (int j = 0; j < s[i].size(); j++) {
            p = p * B + s[i][j];
        }
        st[(int)s[i].size()].insert(p.val());
    }

    vector<ll> ans(m);
    const int mod = 1e9 + 7;
    for (auto &it : st) {
        int x = it.first;
        for (int i = 0; i < m; i++) {
            if (t[i].size() < x) continue;
            Z p = 0;
            for (int j = 0; j < x; j++) {
                p = p * B + t[i][j];
            }
            ll l = 1, r = t[i].size() - x + 1;
            if (it.second.count(p.val())) {
                ans[i] = (ans[i] + l * r) % mod;
            }
            for (int j = x; j < t[i].size(); j++) {
                l++;
                r--;
                p -= power[x - 1] * t[i][j - x];
                p = p * B + t[i][j];
                if (it.second.count(p.val())) {
                    ans[i] = (ans[i] + l * r) % mod;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}