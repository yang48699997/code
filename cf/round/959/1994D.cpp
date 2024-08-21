#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i + 1];
    vector<pair<int,int>> ans;
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = n - 1; i > 0; i--) {
        auto it = st.begin();
        vector<int> v(i, -1);
        while (it != st.end()) {
            int p = a[*it] % i;
            if (v[p] == -1) v[p] = *it;
            else {
                ans.push_back({*it, v[p]});
                st.erase(it);
                break;
            }
            it++;
        }
    }
    cout << "YES\n";
    for (int i = n - 2; i >= 0; i--) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
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