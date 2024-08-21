#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<tuple<int, int, int>, int> mp;

// int dfs(int a, int b ,int c) {
//     if (a > b) swap(a, b);
//     if (b > c) swap(b, c);
//     if (a > b) swap(a, b);
//     if (mp.count({a, b, c})) return mp[{a, b, c}];
//     int ans = 1;
//     if (a > 1) {
//         for (int i = 1; i < a; i++) {
//             ans &= dfs(i, a - i, b);
//             ans &= dfs(i, a - i, c);
//         }
//     }
//     if (b > 1) {
//         for (int i = 1; i < b; i++) {
//             ans &= dfs(i, b - i, a);
//             ans &= dfs(i, b - i, c);
//         }
//     }
//     if (c > 1) {
//         for (int i = 1; i < c; i++) {
//             ans &= dfs(i, c - i, a);
//             ans &= dfs(i, c - i, b);
//         }
//     }
//     ans ^= 1;
//     mp[{a, b, c}] = ans;
//     return ans;
// }

int gcd(int x, int y) {
    while (y) {
        int t = y;
        y = x % y;
        x = t;
    };
    return x;
};

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int g = gcd(a, b);
    g = gcd(g, c);
    int ok = 0;
    ok += (a / g % 2) + b / g % 2 + c / g % 2; 
    if (ok != 3) cout << "YES\n";
    else cout << "NO\n";
    // int k = 20;
    // for (int i = 1; i <= k; i++) {
    //     for (int j = 1; j <= k; j++) {
    //         for (int p = 1; p <= k; p++) {
    //             if (dfs(i, j, p)) continue;
    //             else {
    //                 cout << i << " " << j << " " << p << "\n";
    //             }
    //         }
    //     } 
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    // mp = map<tuple<int, int, int>, int> ();
    // mp[{1, 1, 1}] = 0;
    while (T--) {
        solve();
    }
    return 0;
}