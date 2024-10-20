#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    int t = 1;
    cout << t << "\n";
    int a = rng() % 13 + 1;
    int b = rng() % 13 + 1;
    int c = rng() % 13 + 1;
    int d = rng() % 13 + 1;
    map<int, string> mp = {
        {1, "A"},
        {11, "J"},
        {12, "Q"},
        {13, "K"},
    };
    if (mp.count(a)) cout << mp[a] << " ";
    else cout << a << " ";
    if (mp.count(b)) cout << mp[b] << " ";
    else cout << b << " ";
    if (mp.count(c)) cout << mp[c] << " ";
    else cout << c << " ";
    if (mp.count(d)) cout << mp[d] << "\n";
    else cout << d << "\n";
    return 0;
}