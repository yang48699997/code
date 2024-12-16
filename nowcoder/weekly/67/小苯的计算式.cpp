#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;

    string C = to_string(c);
    n -= C.size() + 2;

    int ans = 0;
    for (int i = 0; i <= c; i++) {
        string a = to_string(i);
        string b = to_string(c - i);
        if (a.size() + b.size() == n) ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}