#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    int n = rng() % 500 + 1;
    string s = "";
    for (int i = 0; i < n; i++) {
        int x = rng() % 3;
        if (x == 0) s += '.';
        else if (x == 1) s += 'p';
        else s += 's';
    }

    cout << 1 << "\n";
    cout << n << "\n";
    cout << s << "\n";
    return 0;
}