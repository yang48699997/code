#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    char a, b, c;
    cin >> a >> b >> c;
    
    vector<int> l(3), g(3);
    if (a == '>') {
        g[1]++;
        l[0]++;
    } else {
        g[0]++;
        l[1]++;
    }

    if (b == '>') {
        g[2]++;
        l[0]++;
    } else {
        g[0]++;
        l[2]++;
    }

    if (c == '>') {
        g[2]++;
        l[1]++;
    } else {
        g[1]++;
        l[2]++;
    }

    for (int i = 0; i < 3; i++) {
        char now = 'A' + i;
        if (l[i] == 1 && g[i] == 1) {
            cout << now << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}