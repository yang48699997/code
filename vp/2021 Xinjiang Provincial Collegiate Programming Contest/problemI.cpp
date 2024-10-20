#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type, less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> pbds;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    pbds st;
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert({a[i], i});
    }
    for (int i = 0; i < m; i++) cin >> b[i];
    cin >> l >> r;

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int x = b[i];
        if (x == 0) {
            if (l == 0 || r == 0 || (l < 0 && r > 0)) ans += n;
        } else {
            int cl = l, cr = r;
            if (x < 0) {
                cl = -r;
                cr = -l;
                x = -x;
            }
            int mi = cl / x;
            if (mi * x < cl) mi++;
            int mx = cr / x;
            if (mx * x > cr) mx--;
            if (mi > mx) continue;
            ans += st.order_of_key({mx, n})  - st.order_of_key({mi, -1});
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}