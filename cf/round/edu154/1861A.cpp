#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    string s;
    cin >> s;
    vector<int> cnt(10);
    for (int i = 0; i < 10; i++) {
        cnt[s[i] - '0'] = i;
    }
    if (cnt[1] < cnt[7]) cout << 17 << "\n";
    else cout << "71\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}