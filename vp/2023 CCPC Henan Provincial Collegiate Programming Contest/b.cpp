#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   

    vector<int> tmp = a;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    map<int, int> mp;
    for (int i = 0; i < tmp.size(); i++) {
        mp[tmp[i]] = i;
    }

    vector<vector<int>> mi(20, vector<int> (n)); 
    vector<vector<int>> mx(20, vector<int> (n)); 
    vector<int> lg(n + 1);
    for (int i = 0; i < n; i++) {
        mi[0][i] = a[i];
        mx[0][i] = a[i];
        if (i > 0) lg[i + 1] = lg[(i + 1) / 2] + 1;
    }
    for (int k = 1; k < 20; k++) {
        int len = 1 << (k - 1);
        for (int j = 0; j < n; j++) {
            mi[k][j] = min(mi[k - 1][j], mi[k - 1][min(n - 1, j + len)]);
            mx[k][j] = max(mx[k - 1][j], mx[k - 1][min(n - 1, j + len)]);
        }
    }

    auto q1 = [&](int l, int r) -> int {
        int len = r - l + 1; 
        return min(mi[lg[len]][l], mi[lg[len]][r - (1 << lg[len]) + 1]);
    };
    auto q2 = [&](int l, int r) -> int {
        int len = r - l + 1;
        return max(mx[lg[len]][l], mx[lg[len]][r - (1 << lg[len]) + 1]);
    };


    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int pre = 0;
        int ok = 1;
        for (int j = i; j <= n; j += i) {
            int mi = q1(j - i, j - 1);
            int mx = q2(j - i, j - 1);
            if (mi < pre) {
                ok = 0;
                break;
            }
            if (j != n && j + i >= n) {
                int now = q1(j, n - 1);
                if (now < mx) {
                    ok = 0;
                    break;
                }
            }
            pre = mx;
        }
        ans += ok;
    }

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}