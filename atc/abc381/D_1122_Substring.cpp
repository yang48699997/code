#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    auto check = [&](vector<int> a) -> int {
        int n = a.size();
        queue<int> q;
        set<int> st;

        int ans = 0;
        for (int i = 1; i < n; i += 2) {
            if (a[i] != a[i - 1]) {
                q = queue<int> ();
                st.clear();
            } else {
                if (st.count(a[i])) {
                    while (!q.empty()) {
                        int x = q.front();
                        q.pop();
                        st.erase(x);
                        if (x == a[i]) break;
                    }
                }
                st.insert(a[i]);
                q.push(a[i]);
                ans = max(ans, 2 * (int)q.size());
            }

        }
        return ans;
    };

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i + 1];
    }

    cout << max(check(a), check(b)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}