#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int p = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != 1 && a[i] != -1) {
            p = i;
            break;
        }
    }

    vector<int> ans(1);
    int l = 0;
    int r = 0;
    int L = 0, R = 0;
    for (int i = 0; i < p; i++) {
        if (a[i] == 1) {
            r++;
            l++;
            l = min(l, 0);
        } else {
            l--;
            r--;
            r = max(r, 0);
        }
        L = min(l, L);
        R = max(R, r);
    }
    int l1 = 0;
    int r1 = 0;
    for (int i = n - 1; i > p; i--) {
        if (a[i] == 1) {
            r1++;
            l1++;
            l1 = min(l1, 0);
        } else {
            l1--;
            r1--;
            r1 = max(r1, 0);
        }
        L = min(l1, L);
        R = max(R, r1);
    }
    for (int i = L; i <= R; i++) {
        ans.push_back(i);
    }

    int now = p;
    for (int i = l1 + l; i <= r1 + r; i++) {
        ans.push_back(i + a[p]);
    }


    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
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