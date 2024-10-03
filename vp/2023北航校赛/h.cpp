#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct Gauss {
    const double eps = 1e-6;
    int n;
    vector<vector<T>> a;
    Gauss () : n(0), a(0) {}
    Gauss (int n_) : n(n_), a(n_, vector<T> (n_ + 1)) {}
    Gauss (vector<vector<T>> a_) : a(a_), n((int)a.size()) {}

    void set(int i, int j, T val) {
        a[i][j] = val;
    }
    T get(int i, int j) {
        return a[i][j];
    }
    int work() {
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

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<int> len(100);
    vector<int> pow{1, 10, 100};
    for (int i = 0; i < 100; i++) {
        len[i] = to_string(i).size();
    }

    Gauss<double> G(2);
    int ans = 0;
    for (int a = 1; a < 100; a++) {
        for (int e = 1; e < 100; e++) {
            int AA = a * pow[len[e]] + e;
            if (AA > A) continue;
            for (int b = 1; b < 100; b++) {
                int g = AA - a * e;
                if (g <= 0 || g % b != 0) continue;
                g /= b;
                if (g > 99) continue;
                for (int f = 1; f < 100; f++) {
                    int BB = b * pow[len[f]] + f;
                    if (BB > B) continue;
                    int h = BB - a * f;
                    if (h <= 0 || h % b != 0) continue;
                    h /= b;
                    if (h > 99) continue;
                    G.set(0, 0, pow[len[g]] - e); 
                    G.set(0, 1, -g); 
                    G.set(0, 2, -g); 
                    G.set(1, 0, f);
                    G.set(1, 1, h - pow[len[h]]);
                    G.set(1, 2, h);
                    if (G.work()) {
                        int c = G.get(0, 2) + G.eps;
                        int d = G.get(1, 2) + G.eps;
                        // cerr << a << " " << b << " " << c << " " << d << "\n";
                        // cerr << e << " " << f << " " << g << " " << h << "\n";
                        // cerr << "-------------------\n";
                        if (c <= 0 || d <= 0 || c > 99 || d > 99) continue;
                        if (c * e + d * g != c * pow[len[g]] + g || c * pow[len[g]] + g > C) continue;
                        if (d * pow[len[h]] + h > D || d * pow[len[h]] + h != c * f + d * h) continue;
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}