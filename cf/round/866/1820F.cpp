#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        while (k--) {
            int x;
            cin >> x;
            x--;
            p[i].push_back(x);
        }
    }

    set<int> st;
    vector<int> r(n), zero(n);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        int k = p[i].size();
        int ok = 1;
        for (int j = 0; j < k; j++) {
            if (st.count(p[i][j])) {
                ok = 0;
                break;
            } else st.insert(p[i][j]);
        }

        if (!ok) break;
        
        if (k == 0) cnt++;
        if (cnt) r[i] = m;
        else r[i] = st.size();
    }

    int ok = -1;
    int now = -1;
    map<int, int> mp;
    st.clear();
    st.insert(n);

    for (int i = 0; i < n; i++) {
        int k = p[i].size();

        if (k == 0) {
            zero[i] = 1;
            ok = i;
            st.insert(i);
            continue;
        }

        int mx = -1;
        for (int j = 0; j < k; j++) {
            int x = p[i][j];
            if (mp.count(x)) {
                mx = max(mx, mp[x]);
            }
        }
        if (mx == -1) {
            for (int j = 0; j < k; j++) {
                int x = p[i][j];
                mp[x] = i;
            }
            if (ok > now) {
                zero[i] = 1;
                st.insert(i);
            }
            continue;
        }

        zero[i] = 1;

        auto it = st.lower_bound(mx);
        int P = *it;

        if (P == n) {
            st.clear();
            st.insert(n);
            now = i;
            mp.clear();
        } else {
            while (now < P) {
                int x = ++now;
                for (int nxt : p[x]) {
                    mp.erase(nxt);
                }
                st.erase(x);
            }
            st.insert(i);
            for (int j = 0; j < k; j++) {
                mp[p[i][j]] = i;
            }
            
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || zero[i - 1]) ans = max(ans, r[i]);
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