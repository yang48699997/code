#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void generateMatrix(int m, int n, int maxValue) {
    cout << m << " " << n << "\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double now = static_cast<double>(rng() % (maxValue * 100)) / 100.0;
            cout << fixed << setprecision(2) << now << " ";
        }
        cout << "\n";
    }
}

int main() {
    int rows = 50;       
    int cols = 50;       
    int maxValue = 1000;  

    generateMatrix(rows, cols, maxValue);

    return 0;
}
