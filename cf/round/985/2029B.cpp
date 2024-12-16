#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s, r;
    cin >> s >> r;

    vector<int> cnt(2);
    for (char c : s) {
        cnt[c - '0']++;
    }

    for (char c : r) {
        if (cnt[0] == 0 || cnt[1] == 0) {
            cout << "NO\n";
            return;
        }
        cnt[1 ^ (c - '0')]--;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}