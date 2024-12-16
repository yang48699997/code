#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;

    if (a ^ b) {
        if (a) cout << "Yes\n";
        else cout << "No\n";
    } else cout << "Invalid\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}