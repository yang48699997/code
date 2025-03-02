#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    k -= 2;

    vector<int> a(n);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        p[a[i]].push_back(i);
    }

    vector<int> mnl(n, -1), mnr(n, n), mxl(n, -1), mxr(n, n);
    vector<int> b(n);

    int cur = 0;
    for (int i = 0; i < n; i++) {
        while (cur > 0 && a[i] < a[b[cur - 1]]) {
            mnr[b[cur - 1]] = i;
            cur--;
        }
        b[cur++] = i;
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        while (cur > 0 && a[i] > a[b[cur - 1]]) {
            mxr[b[cur - 1]] = i;
            cur--;
        }
        b[cur++] = i;
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (cur > 0 && a[i] <= a[b[cur - 1]]) {
            mnl[b[cur - 1]] = i;
            cur--;
        }
        b[cur++] = i;
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (cur > 0 && a[i] > a[b[cur - 1]]) {
            mxl[b[cur - 1]] = i;
            cur--;
        }
        b[cur++] = i;
    }


    ll ans = 0;
    for (int L = 0; L < n; L++) {
        int R = k - L;
        if (R < 0 || R >= n) continue;

        int m = p[R].size();
        vector<int> pre(m, -1);
        int tot = 0;

        int pr = 0;
        int nxt = 0;
        for (int j = 0; j < p[L].size(); j++) {
            int pl = p[L][j];
            ll d = pl - mnl[pl];

            while (pr < m && p[R][pr] <= pl) {
                if (pre[pr] != -1) {
                    tot -= mxr[p[R][pr]] - pre[pr];
                } 
                pr++;
                nxt = max(nxt, pr);
            }

            cur = pr;
            while (cur < m && pre[cur] == -1) {
                if (mxl[p[R][cur]] < mnr[pl]) {
                    pre[cur] = p[R][cur];
                    tot += mxr[p[R][cur]] - p[R][cur];
                } else {
                    nxt = max(nxt, cur);
                    break;
                }
                cur = lower_bound(p[R].begin(), p[R].end(), mxr[p[R][cur]]) - p[R].begin();
            }
            cur = nxt;
            while (cur < m && pre[cur] == -1) {
                if (mxl[p[R][cur]] < mnr[pl]) {
                    pre[cur] = p[R][cur];
                    tot += mxr[p[R][cur]] - p[R][cur];
                } else {
                    nxt = max(nxt, cur);
                    break;
                }
                cur = lower_bound(p[R].begin(), p[R].end(), mxr[p[R][cur]]) - p[R].begin();
            }

            ans += d * tot;
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