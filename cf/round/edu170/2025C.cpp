#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    vector<int> num;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        num.push_back(x);
    }

    int ans = 0;
    int p = 0;
    sort(num.begin(), num.end());
    int pre = num[0] - 1;
    num.erase(unique(num.begin(), num.end()), num.end());
    int res = 0;
    for (int i : num) {
        if (i == pre + 1) {
            p++;
            res += cnt[i];
            if (p > k) {
                p--;
                res -= cnt[i - k];
            }
        } else {
            p = 1;
            res = cnt[i];
        }
        pre = i;
        ans = max(ans, res);
    }

    cout << ans << "\n";
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