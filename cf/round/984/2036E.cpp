#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> a(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (i == 0) a[j].push_back(x);
            else {
                x |= a[j].back();
                a[j].push_back(x);
            }
        }
    } 

    while (q--) {
        int m;
        cin >> m;
        int l = 0, r = n - 1;

        while (m--) {
            int rr, c;
            char o;
            cin >> rr >> o >> c;
            rr--;

            if (o == '>') {
                auto it = upper_bound(a[rr].begin(), a[rr].end(), c);
                l = max(l, (int)(it - a[rr].begin()));
            } else {
                auto it = lower_bound(a[rr].begin(), a[rr].end(), c);
                r = min(r, (int)(it - a[rr].begin()) - 1);
            }


        }

        if (l > r) cout << "-1\n";
        else cout << l + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}