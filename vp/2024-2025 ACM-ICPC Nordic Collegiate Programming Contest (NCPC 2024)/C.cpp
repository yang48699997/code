#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    cout << n / 2 << "\n";
    
    int add = (n & 1);
    while (n) {
        cout << 2 + add << " \n"[2 + add == n];
        n -= 2 + add;
        add = 0;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}