#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    cout << 1 << "\n";
    int n = 10;
    ll k = rng() % (1LL << 5);
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++) {
        ll now = rng() % (1LL << 5);
        cout << now << " \n"[i == n - 1];
    }
    return 0;
}