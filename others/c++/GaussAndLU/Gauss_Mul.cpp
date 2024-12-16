#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

using ll = long long;

template<class T>
struct Gauss {
    const double eps = 1e-6;
    int n;
    vector<vector<T>> a;
    Gauss () : n(0), a(0) {}
    Gauss (int n_) : n(n_), a(n_, vector<T> (n_ + 1)) {}
    Gauss (vector<vector<T>> a_) : a(a_), n((int)a_.size()) {}

    void set(int i, int j, T val) {
        a[i][j] = val;
    }
    T get(int i, int j) {
        return a[i][j];
    }
    int work() {
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            for (int k = i; k < n; k++){
                if (fabs(a[k][i]) > eps){
                    swap(a[k], a[i]);
                    break;
                }
            }
            if (fabs(a[i][i]) < eps){
                return 0;
            }
            for (int j = n; j >= i; j--){
                a[i][j] /= a[i][i];
            } 

            for (int k = i + 1; k < n; k++){
                for (int j = n; j >= i; j--){
                    a[k][j] -= a[k][i] * a[i][j];
                }
            } 
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++){
                a[i][n] -= a[i][j] * a[j][n];
            }
        }
        return 1;
    }
};

using G = Gauss<double>;

void solve() {
    int n;
    cin >> n;

    vector<vector<double>> g(n, vector<double> (n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> g[i][j];
        }
    } 

    G gauss(g);

    auto start = high_resolution_clock::now();

    gauss.work();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "运行时间: " << duration.count() * 100 << " ms" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}