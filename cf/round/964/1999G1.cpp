#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int p;
int q(int a, int b) {
    if (a >= p) a++;
    if (b >= p) b++;
    int res = a * b;
    return res;
}

int solve(int n) {
    int l = 1, r = 1001;
    p = n;
    int t = 0;
    while (l <= r) {
        int d = (r - l) / 3;
        int x = l + d;
        int y = r - d;
        int res = q(x, y);
        if (x > 1000 || x < 1) cerr << "-";
        if (y > 1000 || y < 1) cerr << "-";
        if (res == x * y) {
            l = y + 1;
        } else if (res == (x + 1) * (y + 1)){
            r = x - 1;
        } else {
            l = x + 1;
            r = y - 1;
        }
        t++;
    }    
    if (t > 7) cerr << n << "\n";
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ok = 0;
    for (int i = 2; i < 1000; i++) {
        int res = solve(i);
        if (res != i) cout << i << "\n";
        else ok++;
    }
    cout << "ok:" << ok;
    return 0;
}