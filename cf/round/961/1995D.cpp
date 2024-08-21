#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, c, k;
    cin >> n >> c >> k;
    string s;
    cin >> s;
    vector<int> v(1 << c);
    int mask = (1 << c) - 1;
    vector<int> cnt(c);

    v[mask - (1 << (s.back() - 'A'))] = 1;
    for (int i = 0; i < k; i++) {
        cnt[s[i] - 'A']++;
        int x = s[i] - 'A';
        if (cnt[x] == 1) mask ^= (1 << x);
    } 
    v[mask] = 1;
    for (int i = k; i < n; i++) {
        int x = s[i - k] - 'A';
        int y = s[i] - 'A';
        if (cnt[x] == 1) {
            mask |= (1 << x);
        }
        cnt[x]--;
        if (cnt[y] == 0) {
            mask ^= (1 << y);
        }
        cnt[y]++;
        v[mask] = 1;
    }
    int ans = c;
    for (int i = (1 << c) - 1; i > 0; i--) {
        if (v[i]) {
            for (int j = 0; j < c; j++) {
                if (1 << j & i) v[1 << j ^ i] = 1;
            }
        } else ans = min(ans, __builtin_popcount(i));
    }
    cout << ans << "\n";
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