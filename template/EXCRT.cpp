#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BigInt {
	static const int base = 1000000000;
	static const int base_digits = 9;
    vector<int> a;
    int sign;
    BigInt() : sign(1) {}
    BigInt operator-() const {
        BigInt res = *this;
        res.sign = -sign;
        return res;
    }
    BigInt(ll v) {
        *this = v;
    }
    BigInt(const string &s) {
        read(s);
    }
    void operator=(const BigInt &v) {
        sign = v.sign;
        a = v.a;
    }
    void operator=(ll v) {
        a.clear();
        sign = 1;
        if (v < 0) sign = -1, v = -v;
        for (; v > 0; v = v / base) {
            a.push_back(v % base);
        }
    }

    BigInt operator+(const BigInt &v) const {
        if (sign == v.sign) {
            BigInt res = v;
            for (int i = 0, carry = 0; i < (int)max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int)res.a.size()) {
                    res.a.push_back(0);
                }
                res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry) {
                    res.a[i] -= base;
                }
            }
            return res;
        }
        return *this - (-v);
    }
    BigInt operator-(const BigInt &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                BigInt res = *this;
                for (int i = 0, carry = 0; i < (int)v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry) {
                        res.a[i] += base;
                    }
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
    void operator*=(int v) {
        check(v);
        for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i) {
            if (i == (int)a.size()) {
                a.push_back(0);
            }
            ll cur = a[i] * (ll)v + carry;
            carry = (int)(cur / base);
            a[i] = (int)(cur % base);
        }
        trim();
    }
    void operator/=(int v) {
        check(v);
        for (int i = (int)a.size() - 1, rem = 0; i >= 0; --i) {
            ll cur = a[i] + rem * (ll)base;
            a[i] = (int)(cur / v);
            rem = (int)(cur % v);
        }
        trim();
    }
    int operator%(int v) const {
        if (v < 0) {
            v = -v;
        }
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i) {
            m = (a[i] + m * (ll)base) % v;
        }
        return m * sign;
    }

    void operator+=(const BigInt &v) {
        *this = *this + v;
    }
    void operator-=(const BigInt &v) {
        *this = *this - v;
    }
    BigInt operator*(int v) const {
        BigInt res = *this;
        res *= v;
        return res;
    }
    BigInt operator/(int v) const {
        BigInt res = *this;
        res /= v;
        return res;
    }
    void operator%=(const int &v) {
        *this = *this % v;
    }

    bool operator<(const BigInt &v) const {
        if (sign != v.sign) return sign < v.sign;
        if (a.size() != v.a.size()) return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
        return false;
    }
    bool operator>(const BigInt &v) const {
        return v < *this;
    }
    bool operator<=(const BigInt &v) const {
        return !(v < *this);
    }
    bool operator>=(const BigInt &v) const {
        return !(*this < v);
    }
    bool operator==(const BigInt &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const BigInt &v) const {
        return *this < v || v < *this;
    }

    BigInt abs() const {
        BigInt res = *this;
        res.sign *= res.sign;
        return res;
    }
    void check(int v) { 
        if (v < 0) {
            sign = -sign;
            v = -v;
        }
    }
    void trim() { 
        while (!a.empty() && !a.back()) a.pop_back();
        if (a.empty()) sign = 1;
    }
    bool isZero() const { 
        return a.empty() || (a.size() == 1 && !a[0]);
    }
    friend BigInt gcd(BigInt a,BigInt b){
        int tims(0);if(a<b) swap(a,b);
        while(!(a%2)&&!(b%2)) a=a/2,b=b/2,++tims;
        while(!(a==b)){
            int t1(a%2),t2(b%2);
            !t1?a=a/2:(!t2?b=b/2:a=a-b);
            if(a<b) swap(a,b);
        }
        while(tims--) a=a*2;
        return a;
    }
    friend BigInt lcm(const BigInt &a, const BigInt &b) {
        return a / gcd(a, b) * b;
    }
    friend BigInt qpow(BigInt a, BigInt n){
        BigInt res = 1;
        while (n>0){
            if (n%2==1) res = res * a;
            a = a * a;
            n /= 2;
        }
        return res;
    }
    friend BigInt sqrt(BigInt x,BigInt y){
        if(x==1) return x;
        BigInt l=0,r=x+1;
        while(l<r){
            BigInt mid=(l+r)/2;
            if(qpow(mid,y)>x) r=mid;
            else l=mid+1;
        }
        return l-1;
    }
    friend BigInt factorial(BigInt x){
        BigInt ans=1;
        for(BigInt i=1;i<=x;i+=1) ans*=i;
        return ans;
    }
    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++) x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
    friend istream &operator>>(istream &stream, BigInt &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
    friend ostream &operator<<(ostream &stream, const BigInt &v) {
        if (v.sign == -1) stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int)v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    typedef vector<ll> vll;
    BigInt operator*(const BigInt &v) const { 
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size()) a.push_back(0);
        while (b.size() < a.size()) b.push_back(0);
        while (a.size() & (a.size() - 1)) a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        BigInt res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int)c.size(); i++) {
            ll cur = c[i] + carry;
            res.a.push_back((int)(cur % 1000000));
            carry = (int)(cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
    friend pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) { 
        int norm = base / (b1.a.back() + 1);
        BigInt a = a1.abs() * norm;
        BigInt b = b1.abs() * norm;
        BigInt q, r;
        q.a.resize(a.a.size());
        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((ll)base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0) r += b, --d;
            q.a[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<ll> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int)p.size(); i++) p[i] = p[i - 1] * 10;
        vector<int> res;
        ll cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back((int)(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && !res.back()) res.pop_back();
        return res;
    }
    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[i + j] += a[i] * b[j];
                }
            }
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++) a2[i] += a1[i];
        for (int i = 0; i < k; i++) b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int)a1b1.size(); i++) r[i] -= a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++) r[i] -= a2b2[i];

        for (int i = 0; i < (int)r.size(); i++) res[i + k] += r[i];
        for (int i = 0; i < (int)a1b1.size(); i++) res[i] += a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++) res[i + n] += a2b2[i];
        return res;
    }

    void operator*=(const BigInt &v) {
        *this = *this * v;
    }
    BigInt operator/(const BigInt &v) const {
        return divmod(*this, v).first;
    }
    void operator/=(const BigInt &v) {
        *this = *this / v;
    }
    BigInt operator%(const BigInt &v) const {
        return divmod(*this, v).second;
    }
    void operator%=(const BigInt &v) {
        *this = *this % v;
    }
};

using B = BigInt;

template<class T>
struct EXCRT {
    int n;
    T x, y, d;
    vector<T> A, B;
    EXCRT () : n(0), A(0), B(0) {}
    void add(T a, T b) {
        n++;
        A.emplace_back(a);
        B.emplace_back(b);
    }
    void exgcd(T &x, T &y, T a, T b) {
        if (b == 0) {
            d = a;
            x = 1;
            y = 0;
        } else {
            exgcd(y, x, b, a % b);
            y -= a / b * x;
        }
    }
    T gcd(T a, T b) {
        while (b != 0) {
            T tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
    T lcm(T a, T b) {
        return a * b / gcd(a, b);
    }
    T work() {
        if (n == 0) return -1;
        T a = A[0];
        T b = B[0];
        for (int i = 1; i < n; i++) {
            exgcd(x, y, a, A[i]);
            T c = B[i] - b;
            if (c % d != 0) {
                return -1;
            }
            x = x * c / d % (A[i] / d);
            if (x < 0) x += A[i] / d;
            T mod = lcm(a, A[i]);
            b = (a * x + b) % mod;
            if (b < 0) b += mod;
            a = mod;
        }
        return b % a;
    }
};

using E = EXCRT<B>; 
