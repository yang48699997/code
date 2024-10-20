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
 

int maxLcsplength(string str) {
	if (str.length() == 0) {
		return 0;
	}
	int len = (int)(str.length() * 2 + 1);
	char *chaArr = new char[len];
	int* pArr = new int[len];
	int index = 0;
	for (int i = 0; i < len;i++) {
		chaArr[i] = (i & 1) == 0 ? '#' : str[index++];
	}
	int R = -1;
	int C = -1;
	int maxn = 0;
	for (int i = 0; i < len; i++) {
		pArr[i] = R > i ? min(R - i, pArr[2 * C - i]) : 1;
		while (i + pArr[i]<len && i - pArr[i]>-1) {
			if (chaArr[i + pArr[i]] == chaArr[i - pArr[i]]) {
				pArr[i]++;
			}
			else {
				break;
			}
		}
		if (i + pArr[i] > R) {
			R = i + pArr[i];
			C = i;
		}
		maxn = max(maxn, pArr[i]);
	}
	delete[] chaArr;
	delete[] pArr;
	return maxn - 1;
}

void solve() {
    int len, n;
    Z k;
    cin >> len >> n >> k;
    k = 1 / k;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m = maxLcsplength(s);
    ll ans = 0;
    int l = 0;
    ll now = 0;
    for (int i = 0; i < n; i++) {
        if (l == i - m) now -= a[l++];
        while (l < i && a[l] <= 0) now -= a[l++];
        now += a[i];
        ans = max(ans, now);
        if (now <= 0) {
            now = 0;
            l = i + 1;
        }
    }

    k *= ans;
    cout << k << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}