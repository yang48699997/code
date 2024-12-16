#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    char c1, c2;
    cin >> n >> c1 >> c2;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] != c1) s[i] = c2;
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}