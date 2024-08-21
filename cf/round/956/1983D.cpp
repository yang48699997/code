#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int T;
int f(vector<int> &a) {
    int n = a.size();
    int ans = 0;
    ordered_set st;
    st.insert(a[0]);
    for (int i = 1; i < n; i++) {
        ans += st.order_of_key(a[i]);
        ans %= 2;
        st.insert(a[i]);
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int res1 = f(a);
    int res2 = f(b);
    if (res1 < res2) swap(res1, res2);
    if ((res1 - res2) % 2) {
        cout << "NO\n";
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}