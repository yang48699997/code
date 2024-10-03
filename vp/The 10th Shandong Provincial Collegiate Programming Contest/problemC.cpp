#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        p.emplace_back(l, r);
    }
    sort(p.begin(), p.end());
    int now = p[0].first;
    int l = 0;
    multiset<int> st;
    int ans = 0;
    while (l < n) {
        int cl = p[l].first;
        int cr = p[l].second;
        while (!st.empty() && min(*st.begin(), now) < cl) {
            if (*st.begin() < now) {
                st.erase(st.begin());
                continue;
            }
            ans++;
            now = min(*st.begin(), now) + 1;
            st.erase(st.begin());
        }
        now = cl;
        while (l < n && p[l].first == cl) {
            st.insert(p[l].second);
            l++;
        }
    }
    while (!st.empty()) {
        if (*st.begin() < now) {
            st.erase(st.begin());
            continue;
        }
        ans++;
        now = min(*st.begin(), now) + 1;
        st.erase(st.begin());
    }
    cout << ans << "\n";
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