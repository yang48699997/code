#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b != c) {
        cout << "No\n";
        return;
    } 
    if (a == b) {
        cout << "No\n";
        return;
    }
    if (b == d) {
        cout << "No\n";
        return;
    }
    if (a == d) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}