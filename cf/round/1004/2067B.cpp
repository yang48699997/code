#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        x--;
        cnt[x]++;
    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] == 1) {
            cout << "No\n";
            return;
        }
        cnt[i + 1] += max(0, cnt[i] - 2); 
    }

    cout << "Yes\n";
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