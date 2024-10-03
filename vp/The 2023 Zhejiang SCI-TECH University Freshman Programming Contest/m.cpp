#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int len = 5e4;

void solve() {
    int m;
    cin >> m;
    vector<int> pos(len);
    for (int i = 0; i < len; i++) {
        int p = min(m, len);
        pos[i] = p;
        m -= p;
    }
    sort(pos.begin(), pos.end());
    cout << len * 2 << "\n";
    int now = 0;
    string ans;
    int l = 0;
    for (int i = 0; i < len; i++) {
        while (l < len && pos[l] == now) {
            ans += '1';
            l++;
        }
        ans += '0';
        now++;
    }
    while (l < len && pos[l] == now) {
        ans += '1';
        l++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}