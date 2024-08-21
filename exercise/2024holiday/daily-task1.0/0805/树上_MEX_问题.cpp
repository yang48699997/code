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

const int mod = 998244353;
ll powMod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if(y & 1)res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    };
    return res;
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> q(n);
    for (int i = 0; i < n; i++) q[i] = i;
    sort(q.begin(), q.end(), [&](int x1, int x2) {
        return a[x1] < a[x2];
    });

    vector<int> v(n);
    v[q[0]] = 1;
    Z ans = 0;
    vector<int> fa(n, -1);
    vector<Z> dp(n, 1);
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    auto dfs = [&](auto &&self, int x) -> void {
        for (int nxt : e[x]) {
            if (nxt == fa[x]) continue;
            fa[nxt] = x;
            self(self, nxt);
            dp[x] *= dp[nxt];
        }
        dp[x] += 1;
    };

    dfs(dfs, q[0]);
    Z now = -1;
    Z p = 1;
    vector<int> cont(n);
    for (int nxt : e[q[0]]) p *= dp[nxt], cont[nxt] = 1;

    for (int i : q) {
        now += 1;
        // cerr << dp[2] << "\n";
        // cerr << p << " " << now << "\n";
        if (v[i]) continue;
        int cur = i;
        Z last = dp[i];
        Z t = 1;
        while (!v[fa[cur]]) {
            Z l = 1;
            last = dp[fa[cur]];
            for (int nxt : e[fa[cur]]) {
                if (nxt == i || nxt == fa[fa[cur]]) continue;
                l *= dp[nxt];
            }
            dp[fa[cur]] = l + 1;
            t = dp[fa[cur]];
            cur = fa[cur];
        }   
        // cerr << "-----" << i << " " << p << " " << last << " " << t << "\n";
        p *= powMod(last.val(), mod - 2);
        p *= t;
        // cerr << p << "\n";
        ans += p * now;
        p *= powMod(t.val(), mod - 2);
        cur = i;
        while (!v[fa[cur]]) {
            v[fa[cur]] = 1;
            for (int nxt : e[fa[cur]]) {
                if (nxt == cur || nxt == fa[fa[cur]]) continue;
                p *= dp[nxt];
            }
            cur = fa[cur];
        }
        for (int nxt : e[i]) {
            if (nxt == fa[i]) continue;
            p *= dp[nxt];
        }
        v[i] = 1;
    }
    ans += n;
    cout << ans << "\n";
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