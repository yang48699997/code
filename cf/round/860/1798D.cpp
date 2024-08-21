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

    if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end())) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    ll mx = -*min_element(a.begin(), a.end()) + *max_element(a.begin(), a.end());
    mx--;
    multiset<ll> st = {a. begin(), a.end()};
    ll p = *max_element(a.begin(), a.end());
    st.erase(st.find(p));
    cout << p << " ";
    for (int i = 0; i < n - 1; i++) {
        auto it = st.upper_bound(mx - p);
        it--;
        cout << *it << " \n"[i == n - 2];
        p += *it;
        st.erase(it);
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