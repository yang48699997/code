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