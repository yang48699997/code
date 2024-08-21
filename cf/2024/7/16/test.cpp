#include <bits/stdc++.h>
using namespace std;

void solve() {
    int ans = 0;
    int cur = 0;
    vector<int> a(100);
    for (int i = 1; i < 100; i++) {
        a[i] = i;
        cur += a[i];
        ans ^= cur;
        cout << ans << " ";
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}