#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    int ans = n;
    set<pair<int, int>> st;
    st.emplace(1, n);
    st.emplace(0, 0);

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        if (k == 1) {
            auto it = st.upper_bound({l, 0});
            it--;
            if (it -> second >= l) {
                int cl = it -> first;
                int cr = it -> second;
                if (cl < l) {
                    st.erase(it);
                    st.emplace(cl, l - 1);
                    st.emplace(l, cr);
                }
            }
            it = st.lower_bound({l, 0});
            while (it != st.end() && it -> first <= r) {
                int cl = it -> first;
                int cr = it -> second;
                ans -= min(cr, r) - cl + 1;
                st.erase(it);
                if (cr > r) st.emplace(r + 1, cr);
                it = st.lower_bound({l, 0});
            }
        } else {
            auto it = st.upper_bound({l, 0});
            it--;
            int tl = l;
            int tr = r;
            if (it -> second >= l) {
                tl = it -> first;
                ans -= it -> second - tl + 1;
                tr = max(tr, it -> second);
                it = st.erase(it);
            } else it++;
            while (it != st.end() && it -> first <= r) {
                ans -= it -> second - it -> first + 1;
                tr = max(tr, it -> second);
                it = st.erase(it);
            }
            ans += tr - tl + 1;
            st.emplace(tl, tr);
        }
        cout << ans << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}