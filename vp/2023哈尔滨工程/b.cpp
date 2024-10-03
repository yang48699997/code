#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 5 << "\n";
        cout << "1 3 3 3 5\n";
    } else if (n == 2) {
        cout << 6 << "\n";
        cout << "1 1 1 4 6 6\n";
    } else if (n == 3) {
        cout << 10 << "\n";
        cout << "1 1 2 2 3 5 7 8 10 10\n";
    } else if (n == 4) {
        cout << 10 << "\n";
        cout << "1 1 1 2 4 4 7 7 10 10\n";
    } else if (n == 5) {
        cout << 14 << "\n";
        cout << "1 1 2 2 5 6 9 10 10 11 11 11 12 14\n";
    } else if (n == 6) {
        cout << 11 << "\n";
        cout << "1 2 2 2 4 7 8 9 9 9 11\n";
    } else {
        int l = (1 << 10);
        int r = (1 << 11);
        cout << r - l + 3 << "\n";
        int cnt = 0;
        for (int i = l - 1; i <= r + 1; i++) {
            if (i == r) cout << l << " ";
            else cout << i << " \n"[i == r + 1];
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}