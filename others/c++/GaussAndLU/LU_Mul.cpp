#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

template<class T>
struct LU_Decomposition {
    const double eps = 1e-6;
    int n;
    vector<vector<T>> L, U; 
    vector<vector<T>> a;    

    LU_Decomposition() : n(0), L(0), U(0), a(0) {}
    LU_Decomposition(int n_) : n(n_), L(n_, vector<T>(n_, 0)), U(n_, vector<T>(n_, 0)), a(n_, vector<T>(n_)) {}
    LU_Decomposition(vector<vector<T>> a_) : a(a_), n((int)a_.size()), L(n, vector<T>(n, 0)), U(n, vector<T>(n, 0)) {}

    void set(int i, int j, T val) {
        a[i][j] = val;
    }
    
    T get(int i, int j) {
        return a[i][j];
    }

    int decompose() {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                U[i][j] = a[i][j];
                for (int k = 0; k < i; k++) {
                    U[i][j] -= L[i][k] * U[k][j];
                }
            }

            if (fabs(U[i][i]) < eps) {
                return 0;
            }

            for (int j = i; j < n; j++) {
                if (i == j) {
                    L[i][i] = 1; 
                } else {
                    L[j][i] = a[j][i];
                    for (int k = 0; k < i; k++) {
                        L[j][i] -= L[j][k] * U[k][i];
                    }
                    L[j][i] /= U[i][i];
                }
            }
        }
        return 1;
    }
};

using LU = LU_Decomposition<double>;

void solve() {
    int n;
    cin >> n;

    LU lu(n);

    vector<double> val(n);

    vector<vector<double>> g(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            lu.set(i, j, g[i][j]);
        }
        cin >> val[i];
    }

    auto start = high_resolution_clock::now();

    lu.decompose();

    int t = 100;

    while (t--) {
        vector<double> y(n);
        for (int i = 0; i < n; i++) {
            y[i] = val[i];
            for (int j = 0; j < i; j++) {
                y[i] -= lu.L[i][j] * y[j];
            }
        }

        vector<double> x(n);
        for (int i = n - 1; i >= 0; i--) {
            x[i] = y[i];
            for (int j = i + 1; j < n; j++) {
                x[i] -= lu.U[i][j] * x[j];
            }
            x[i] /= lu.U[i][i];
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "运行时间: " << duration.count() << " ms" << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
