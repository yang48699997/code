#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int> ,null_type, less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> ask(q);
    vector<int> nums(q), ans(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i].first >> ask[i].second;
        ask[i].first--;
        ask[i].second--;
    }

    iota(nums.begin(), nums.end(), 0);
    const int block = sqrt(n) * 3 / 2;
    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        if (ask[x1].first / block != ask[x2].first / block) return ask[x1].first / block < ask[x2].first / block;
        return ask[x1].second < ask[x2].second;
    });

    ordered_set st;
    int cl = 0, cr = -1;
    for (int i : nums) {
        int l = ask[i].first;
        int r = ask[i].second;
        while (cr < r) {
            cr++;
            st.insert({a[cr], cr});
        }
        while (cr > r) {
            st.erase({a[cr], cr});
            cr--;
        }
        while (cl < l) {
            st.erase({a[cl], cl});
            cl++;
        }
        while (cl > l) {
            cl--;
            st.insert({a[cl], cl});
        }
        ans[i] = st.find_by_order((r - l) / 2) -> first;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}