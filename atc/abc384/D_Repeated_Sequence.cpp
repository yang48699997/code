#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll t;
    cin >> n >> t;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> pre(n + 1);
    set<ll> st;
    st.insert(0LL);

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
        st.insert(pre[i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        if (pre[i] > t) break;
        ll now = pre[i] + pre[n];
        if (now >= t) {
            if (st.count(now - t)) {
                cout << "Yes\n";
                return;
            }
        } else {
            ll p = t - (t - 1) / pre[n] * pre[n];
            if (st.count(now - p) || st.count(now - p - pre[n])) {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}