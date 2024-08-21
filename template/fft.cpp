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

int main() {
    int n, m;
    cin >> n >> m;
    int mx = m + n + 1;
    int k = 1;
    while (k < mx) k <<= 1;
    vector<Complex> a(k), b(k);
    for (int i = 0; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = {x, 0};
    } 
    for (int i = 0; i <= m; i++) {
        int x;
        cin >> x;
        b[i] = {x, 0};
    } 

    fft(a, k, 1);
    fft(b, k, 1);
    for (int i = 0; i < k; i++) a[i] = a[i] * b[i];
    fft(a, k, -1);
    for (int i = 0; i < mx; i++) cout << (int)(a[i].x / k + 0.5) << " \n"[i == mx - 1];
    return 0;
}