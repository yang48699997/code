#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << " ";
        }
        cout << endl;
        cin >> cnt[i];
        if (cnt[i] == n) return;
    }
    set<int> st;
    for (int i = 1; i < n; i++) st.insert(i);
    vector<int> cnt2(n + 1);
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
        for (int j = 1; j < n; j++) {
            cout << 1 << " ";
        }
        cout << endl;
        cin >> cnt2[i];
        if (cnt2[i] == n) return;
    }

    vector<int> ans(n, -1);
    int p = *max_element(cnt2.begin(), cnt2.end());
    for (int i = 1; i <= n; i++) {
        if (cnt2[i] == p) ans[0] = i;
    }

    cnt[ans[0]]--;
    int t = -1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) t = i;
    }
    for (int i = 1; i <= n; i++) {
        while (cnt[i] != 0) {
            int p = 1;
            int l = 1, r = st.size();
            int c = __lg(r);
            if ((1 << c) != r) c++;
            while (c--) {
                int mid = (l + r) / 2;
                int lef = mid;
                for (int j = 0; j < n; j++) {
                    if (ans[j] == -1) {
                        if (lef) {
                            cout << i << " ";
                            lef--;
                        } else cout << t << " ";
                    } else cout << ans[j] << " ";
                }
                cout << endl;
                int res;
                cin >> res;
                if (res == n) return;
                if (res > n - st.size()) {
                    p = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                    p = l;
                }
            }
            auto it = st.begin();
            while (--p) {
                it++;
            }
            ans[*it] = i;
            st.erase(it);
            cnt[i]--;
        }
    }

    int res = 0;
    while (res != n) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cin >> res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}