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

template<class T>
struct NTT{
    int n, m, len, k;
    static int Mod;
    static int P;
    vector<T> A, B;
    NTT() {}
    NTT(int n_, int m_) : n(n_), m(m_), len(n_ + m_ + 1) {
        k = 1;
        while (k < len) k <<= 1;
        A.resize(k);
        B.resize(k);
    }
    T power(T x, ll y) {
        T res = 1;
        while (y) {
            if (y & 1) res *= x;
            y >>= 1;
            x *= x;
        }
        return res;
    }
    void setA(int i, T p) {
        A[i] = p;
    }
    void setB(int i, T p) {
        B[i] = p;
    }
    void change(vector<T> &a, int n_) {
        vector<int> tmp(n_);
        for (int i = 1; i < n_; i++) {
            tmp[i] = tmp[i / 2] / 2;
            if (i & 1) tmp[i] |= (n_ >> 1);
        }
        for (int i = 1; i < n_; i++) {
            if (tmp[i] > i) swap(a[i], a[tmp[i]]);
        }
        return;
    }
    void ntt(vector<T> &a, int n_, int op) {
        change(a, n_);
        for (int m_ = 2; m_ <= n_; m_ <<= 1) {
            T w1 = power(P, (Mod - 1) / m_);
            // cerr << w1 << "\n";
            if (op == -1) w1 = 1 / w1;
            for (int i = 0; i < n_; i += m_) {
                T wk = 1;
                for (int j = 0; j < m_ / 2; j++) {
                    T x = a[i + j], y = a[i + j + m_ / 2] * wk; 
                    a[i + j] = x + y;
                    a[i + j + m_ / 2] = x - y;
                    wk = wk * w1;
                }
            }
        }
        if (op == -1) {
            Z inv = power(n_, Mod - 2);
            for (int i = 0; i < n_; i++) a[i] *= inv;
        }

        return;
    }
    vector<T> work() {
        ntt(A, k, 1);
        ntt(B, k, 1);
        for (int i = 0; i < k; i++) {
            A[i] *= B[i];
        }
        ntt(A, k, -1);
        return A;
    }
};

template<class T>
int NTT<T>::Mod = 998244353;
template<class T>
int NTT<T>::P = 3;
 
using N = NTT<Z>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    N ntt(n + 1, m + 1);
    for (int i = 0; i < n; i++) {
        ntt.setA(i + 1, a[i]);
    }
    for (int i = 0; i < m; i++) {
        ntt.setB(i + 1, b[i]);
    }
    vector<Z> c = ntt.work();

    Z ans = 0;
    for (int i = 0; i <= n + m; i++) {
        ans += c[i] * i * i;
        cerr << i << ": " << c[i] << "\n";
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}