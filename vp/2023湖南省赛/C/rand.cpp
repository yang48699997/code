#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    int n = 500000, m = 500000;
    cout << n << " " << m << "\n";
    string s;
    for (int i = 0; i < n; i++) {
        int p = rng() % 26;
        s += (char)('a' + p);
    }
    string t;
    for (int i = 0; i < m; i++) {
        int p = rng() % 26;
        t += (char)('a' + p);
    }
    cout << s << "\n" << t << "\n";
    return 0;
}