#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

template<class T>
struct Cholesky_Decomposition {
    const double eps = 1e-6;
    int n;
    vector<vector<T>> L;
    vector<vector<T>> a;

    Cholesky_Decomposition() : n(0), L(0), a(0) {}
    Cholesky_Decomposition(int n_) : n(n_), L(n_, vector<T>(n_, 0)), a(n_, vector<T>(n_)) {}
    Cholesky_Decomposition(vector<vector<T>> a_) : a(a_), n((int)a_.size()), L(n, vector<T>(n, 0)) {}

    void set(int i, int j, T val) {
        a[i][j] = val;
    }

    T get(int i, int j) {
        return a[i][j];
    }

    int decompose() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                T sum = a[i][j];

                for (int k = 0; k < j; k++) {
                    sum -= L[i][k] * L[j][k];
                }

                if (i == j) {
                    if (sum <= 0) return 0;
                    L[i][j] = sqrt(sum);
                } else {
                    L[i][j] = sum / L[j][j];
                }
            }
        }
        return 1;
    }
};

using Cholesky = Cholesky_Decomposition<double>;

void solve() {
    int n;
    cin >> n;

    Cholesky cholesky(n);

    vector<double> val(n);
    vector<vector<double>> g(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            cholesky.set(i, j, g[i][j]);
        }
        cin >> val[i];
    }

    auto start = high_resolution_clock::now();

    if (!cholesky.decompose()) {
        cout << "输入的矩阵不是正定矩阵，无法进行Cholesky分解。" << endl;
        return;
    }

    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        y[i] = val[i];
        for (int j = 0; j < i; j++) {
            y[i] -= cholesky.L[i][j] * y[j];
        }
        y[i] /= cholesky.L[i][i];
    }

    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= cholesky.L[j][i] * x[j];
        }
        x[i] /= cholesky.L[i][i];
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "运行时间: " << duration.count() << " μs" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
