#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        if (s.substr(i, 3) == "#.#") ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}