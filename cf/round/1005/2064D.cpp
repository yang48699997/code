#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(q);
    set<pair<int, int>> st;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        st.insert({x, i});
    }

    int p = 0;
    for (int i = n - 1; i >= 0; i--) {
        int tmp = 0;
        p ^= a[i];
        for (int j = 29; j >= 0; j--) {
            tmp |= (p >> j << j);
            if ((a[i] >> j) & 1) {
                int l = (tmp ^ (1 << j));
                auto it = st.lower_bound({l, -1});
                while (it != st.end() && it->first <= l + (1 << j) - 1) {
                    ans[it->second] = n - i - 1;
                    it = st.erase(it);
                }
            }
        }
    }

    for (auto it : st) {
        ans[it.second] = n;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << " \n"[i == q - 1];
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