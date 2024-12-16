#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) cin >> b[i];

    vector<pair<int, char>> ans;

    auto cal = [&](int l, int r, int p) -> bool {
        if (l == r) return true;
        int mx = a[l];
        int mi = a[l];
        int pos = l;
        for (int i = l; i <= r; i++) {
            mx = max(a[i], mx);
            mi = min(a[i], mi);
            if (a[i] == mx) pos = i;
        }
        if (mi == mx) return false;
        int cl, cr;
        if (pos < r) {
            ans.push_back({pos + p - l, 'R'});
            cl = pos;
            cr = pos + 1;
        } else {
            while (pos >= l && a[pos] == mx) pos--;
            ans.push_back({pos + p - l + 1, 'L'});
            cl = pos;
            cr = pos + 1;
        }
        while (cl > l) {
            ans.push_back({cl + p - l, 'L'});
            cl--;
        }
        while (cr < r) {
            ans.push_back({p, 'R'});
            cr++;
        }
        return true;
    };

    int l = 0;
    for (int i = 0; i < k; i++) {
        int sum = 0;
        int p = l;
        while (l < n && sum < b[i]) {
            sum += a[l++];
        }
        if (sum != b[i]) {
            cout << "NO\n";
            return;
        }
        if (!cal(p, l - 1, i + 1)) {
            cout << "NO\n";
            return;
        }
    }
    
    if (l != n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}