#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    const ll mx1 = 1e12;
    const ll mx2 = 1e7;
    ll n = 1e3, m = rng() % n + 1, k = rng() % mx1;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rng() % mx2;
        k += a[i];
    }
    cout << n << " " << m << " " << k << "\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}