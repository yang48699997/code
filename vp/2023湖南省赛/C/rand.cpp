#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    int n = 5;
    int l = 0, r = 0;
    const int mi = 1e4, mx = 1e5;
    while (l < mi) {
        l = rng() % mx;
    }
    while (r < l) {
        r = rng() % mx;
    }

    cout << n << "\n";
    cout << l << "\n";
    cout << r << "\n";
    int a = rng() % 10;
    cout << a << "\n";
    return 0;
}