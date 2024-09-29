#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<double>> p(n + 1, vector<double> (m + 1));
    double q;
    cin >> q;
    for (int i = n; i > 0; i--) {
        for (int j = m; j > 0; j--) {
            if (i == n && j == m) continue;
            if (i == n) p[i][j] = p[i][j + 1] + q / 4;
            else if (j == m) p[i][j] = p[i + 1][j] + q / 4;
            else {
                double a = p[i + 1][j], b = p[i][j + 1];
                if (a > b) swap(a, b);
                double x = b - a;
                if (x >= q) {
                    p[i][j] = a + q / 4;
                } else {
                    p[i][j] = a / 2 + x / q * (a + x / 2) / 2 + (q - x) / q * b / 2; 
                }
            }
        }
    }
    cout << fixed << setprecision(8) << p[1][1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}