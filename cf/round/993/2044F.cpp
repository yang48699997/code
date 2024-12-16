#include <bits/stdc++.h>
using namespace std;

using ll = __int128;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) sum1 += a[i];
    for (int j = 0; j < m; j++) sum2 += b[j];

    ll tot = sum1 * sum2;
    const int N = 2e5 + 5;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<int> v1(N), v2(N);

    for (int i = 0; i < a.size(); i++) {
        ll now = sum2 * a[i];
        ll t = sum1 - a[i];
        if (t == 0) {
            if (-N < tot - now && tot - now < N) {
                now = tot - now;
                if (now >= 0) v1[now] = 1;
                else v2[-now] = 1;
            }
            continue;
        }
        if (t < 0) {
            int l = 0, r = b.size();
            while (l <= r) {
                int mid = (l + r) / 2;
                if (tot - now - t * b[mid] <= -N) l = mid + 1;
                else r = mid - 1;
            }
            while (l < b.size() && tot - now - t * b[l] < N) {
                ll p = tot - now - t * b[l++];
                if (p >= 0) v1[p] = 1;
                else v2[-p] = 1;
            }
        } else {
            int l = 0, r = b.size();
            while (l <= r) {
                int mid = (l + r) / 2;
                if (tot - now - t * b[mid] >= N) l = mid + 1;
                else r = mid - 1;
            }
            while (l < b.size() && tot - now - t * b[l] > -N) {
                ll p = tot - now - t * b[l++];
                if (p >= 0) v1[p] = 1;
                else v2[-p] = 1;
            }
        }
    }

    while (q--) {
        int x;
        cin >> x;

        if (x >= 0) {
            if (v1[x]) cout << "YES\n";
            else cout << "NO\n";
        } else {
            if (v2[-x]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

/* 
sum1 * bj + sum2 * ai - ai * bj
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    solve();
    return 0;
}