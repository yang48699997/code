#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }

    auto check = [&](int x) -> int {
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            if (v[i] >= x) {
                st.insert(v[i] + w[i]);
            }
        }
        
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (v[i] >= x) continue;
            auto it = st.lower_bound(w[i] + x);
            if (it == st.end()) {
                ok = 0;
                break;
            } else {
                st.erase(it);
            }
        }

        return ok;
    };

    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    cout << r << "\n";
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