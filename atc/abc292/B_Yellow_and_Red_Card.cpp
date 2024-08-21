#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < q; i++) {
        int c, x;
        cin >> c >> x;
        x--;
        if (c == 1) v1[x]++;
        else if (c == 2) v2[x]++;
        else {
            if (v1[x] == 2 || v2[x]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}