#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

struct Complex {
    double x, i;

    Complex(double x = 0, double i = 0) {
        this->x = x;
        this->i = i;
    }

    Complex operator+(const Complex &p) const {
        return Complex({x + p.x, i + p.i});
    };

    Complex operator-(const Complex &p) const {
        return Complex({x - p.x, i - p.i});
    };

    Complex operator*(const Complex &p) const {
        return Complex({x * p.x - i * p.i, i * p.x + x * p.i});
    };

};

void change(vector<Complex> &a, int n) {
    vector<int> tmp(n);
    for (int i = 1; i < n; i++) {
        tmp[i] = tmp[i / 2] / 2;
        if (i & 1) tmp[i] |= (n >> 1);
    }
    for (int i = 1; i < n; i++) {
        if (tmp[i] > i) swap(a[i], a[tmp[i]]);
    }
    return;
}

void fft(vector<Complex> &a, int n, int op) {
    change(a, n);
    for (int m = 2; m <= n; m <<= 1) {
        Complex w1 = {cos(2 * PI / m), sin(2 * PI / m) * op};
        for (int i = 0; i < n; i += m) {
            Complex wk = {1, 0};
            for (int j = 0; j < m / 2; j++) {
                Complex x = a[i + j], y = a[i + j + m / 2] * wk;
                a[i + j] = x + y;
                a[i + j + m / 2] = x - y;
                wk = wk * w1;
            }
        }
    }
    return;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int k = 1;
    while (k <= n * 3) k <<= 1;
    vector<int> ans(n);

    for (int j = 0; j < 5; j++) {
        vector<Complex> p(k), q(k);
        int sum = 0;
        for (int i = 0; i < n * 2; i++) {
            p[i].x = (a[i % n] >> j & 1);
            if (p[i].x) sum++;
        }
        sum >>= 1;
        for (int i = 0; i < n; i++) {
            q[i].x = (b[n - i - 1] >> j & 1);
            if (q[i].x) sum++;
        }
        fft(p, k, 1);
        fft(q, k ,1);
        for (int i = 0; i < k; i++) {
            p[i] = p[i] * q[i];
        }
        fft(p, k, -1);
        for (int i = n; i < n * 2; i++) {
            int res = (p[i].x / k + 0.5);
            ans[i - n] += ((sum - res) << j);
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}