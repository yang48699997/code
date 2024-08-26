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

template<class T>
struct FFT{
    int n, m, len, k;
    vector<T> A, B;
    FFT() {}
    FFT(int n_, int m_) : n(n_), m(m_), len(n_ + m_ + 1) {
        k = 1;
        while (k < len) k <<= 1;
        A.resize(k);
        B.resize(k);
    }
    void setA(int i, int p) {
        A[i] = {p, 0};
    }
    void setB(int i, int p) {
        B[i] = {p, 0};
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
    void fft(vector<Complex> &a, int n_, int op) {
        change(a, n_);
        for (int m_ = 2; m_ <= n_; m_ <<= 1) {
            Complex w1 = {cos(2 * PI / m_), sin(2 * PI / m_) * op};
            for (int i = 0; i < n_; i += m_) {
                Complex wk = {1, 0};
                for (int j = 0; j < m_ / 2; j++) {
                    Complex x = a[i + j], y = a[i + j + m_ / 2] * wk;
                    a[i + j] = x + y;
                    a[i + j + m_ / 2] = x - y;
                    wk = wk * w1;
                }
            }
        }
        return;
    }
    vector<int> work() {
        fft(A, k, 1);
        fft(B, k, 1);
        for (int i = 0; i < k; i++) A[i] = A[i] * B[i];
        fft(A, k, -1);
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = A[i].x / k + 0.5;
        }
        return ans;
    }
};

using F = FFT<Complex>;

