#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }    

    set<ll> st;
    ll mx = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (st.count(a[i])) {
            mx = max(mx, a[i]);
        } else st.insert(a[i]); 
        a[i] = mx;
        ans += mx;
    }
    mx = 0;
    st = set<ll>();
    for (int i = 0; i < n; i++) {
        if (st.count(a[i])) {
            mx = max(mx, a[i]);
        } else st.insert(a[i]); 
        a[i] = mx;
        sum += mx;
    }
    int l = n - 1;
    int cur = l;
    while (cur >= 0 && a[cur] != 0) {
        int cnt = 0;
        while (cur >= 0 && a[cur] == a[l]) {
            cnt++;
            ans += a[cur] * cnt;
            cur--;
        }
        sum -= a[cur + 1] * cnt;
        ans += sum * cnt;
        l = cur;
    }
    cout << ans << "\n";
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