#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
    while (y) {
        ll t = y;
        y = x % y;
        x = t;
    };
    return x;
};
int T;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    set<ll> st;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) continue;
        st.insert(a[i] - a[i - 1]);
    }    
    if (st.empty()) {
        cout << "0\n";
        return;
    }
    ll g = -1;
    for (auto i : st) {
        if (g == -1) g = i;
        else g = gcd(i, g);
    }
    cout << g << "\n";
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