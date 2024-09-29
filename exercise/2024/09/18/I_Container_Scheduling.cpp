#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, l, h;
    cin >> n >> l >> h;
    vector<pair<int, int>> w(n);
    vector<pair<int, int>> ans(n, {-1, -1});
    vector<int> a(1), b(1);
    for (int k = 0; k < n; k++) {
        cin >> w[k].first >> w[k].second;
        int flag = 1;
        for (int i = 0; i < a.size() && flag; i++) {
            for (int j = 0; j < b.size() && flag; j++) {
                int sx = a[i];
                int sy = b[j];
                int tx = a[i] + w[k].first;
                int ty = b[j] + w[k].second;
                int ok = 1;
                if (tx > l || ty > h) ok = 0;
                for (int m = 0; m < k; m++) {
                    if (ans[m].first == -1) continue;
                    if (tx <= ans[m].first || sx >= ans[m].first + w[m].first) {
                        continue;
                    } else if (ty <= ans[m].second || sy >= ans[m].second + w[m].second) {
                        continue;
                    } else {
                        ok = 0;
                    }
                }
                if (ok) {
                    ans[k].first = a[i];
                    ans[k].second = b[j];
                    a.push_back(a[i] + w[k].first);
                    b.push_back(b[j] + w[k].second);
                    flag = 0;
                }
            }
        }
        if (ans[k].first == -1) {
            cout << "-1\n";
        } else {
            cout << ans[k].first << " " << ans[k].second << "\n";
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}