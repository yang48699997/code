#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> h(n), x(n);
    for (int i = 0; i < n; i++) cin >> h[i];    
    for (int i = 0; i < n; i++) cin >> x[i];    

    int l = 1, r = inf;
    while (l <= r) {
        int mid = (l + r) / 2;

        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int d = (h[i] - 1) / mid + 1;
            if (d > m) continue;
            d = m - d;
            cnt[x[i] - d]++;
            cnt[x[i] + d + 1]--;
        }

        int now = 0;
        int ok = 0;
        for (auto [_, c] : cnt) {
            now += c;
            if (now >= k) {
                ok = 1;
                break;
            }
        }
        
        if (ok) r = mid - 1;
        else l = mid + 1;
    }

    if (l > inf) l = -1;

    cout << l << "\n";
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