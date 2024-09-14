#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 5;
int p[N], v[N];
vector<int> op[N];
void init() {
    for (int i = 0; i < N; i++) {
        p[i] = v[i] = 0;
        op[i].clear();
    }
    int tot = 0;
    for (int i = 2; i < N; i++) {
        if (!v[i]) {
            for (int j = i; j < N; j += i) {
                int now = j;
                while (now % i == 0) {
                    op[j].emplace_back(i);
                    now /= i;
                }
            }
            p[tot++] = i;
        }
        for (int j = 0; p[j] * i < N; j++) {
            v[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
}
void solve() {
    int a, b;
    cin >> a >> b;
    ll res = 1LL * a * b;
    int l = 1, r = 1e6;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (mid * mid * mid < res) l = mid + 1;
        else r = mid - 1;
    }
    ll p = 1LL * l * l * l;
    if (p != res) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < op[l].size(); i++) {
        int cnt1 = 0;
        int cnt2 = 0;
        while (a % op[l][i] == 0) cnt1++, a /= op[l][i];
        while (b % op[l][i] == 0) cnt2++, b /= op[l][i];
        if (cnt1 < cnt2) swap(cnt1, cnt2);
        if (cnt1 > cnt2 * 2) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    init();
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}