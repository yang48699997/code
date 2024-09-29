#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mx = 1e9;
int main() {
    cout << 1 << "\n";
    int n = rng() % 1000 + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << rng() % mx + 1 << " \n"[i == n - 1];
    }
    return 0;
}