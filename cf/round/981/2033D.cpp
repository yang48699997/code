#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    set<ll> st = {0};
    ll now = 0;
    for (int i = 0; i < n; i++) {
        now += a[i];
        if (st.count(now)) {
            ans++;
            st.clear();
            st.insert(0);
            now = 0;
        } else {
            st.insert(now);
        }
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