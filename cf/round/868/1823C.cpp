#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        int sq = sqrt(a[i]);
        for (int i = 2; i <= sq; i++) {
            while (cur % i == 0) {
                cnt[i]++;
                cur /= i;
            }
        }
        if (cur > 1) cnt[cur]++;
    }

    vector<int> p;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        p.push_back(it -> second);
    }
    int ans = 0;
    int left = 0;
    for (int i = 0; i < p.size(); i++) {
        ans += p[i] / 2;
        left += p[i] % 2;
    }
    ans += left / 3;
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