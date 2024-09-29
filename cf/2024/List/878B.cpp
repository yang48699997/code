#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    ll m;
    cin >> n >> k >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && a[j] == a[i]) {
            j++;
        }   
        int cnt = j - i;
        while (!p.empty() && p.back().first == a[i]) {
            cnt += p.back().second;
            sum -= p.back().second;
            p.pop_back();
        }
        cnt %= k;
        if (cnt) p.emplace_back(a[i], cnt);
        sum += cnt;
        i = j;
    }
    ll ans = sum * m;
    int cnt = 0;
    int tot = 0;
    n = p.size();
    for (int i = 0; i < n; i++) {
        if (p[i].first == p[n - 1 - i].first && p[i].second + p[n - i - 1].second == k) {
            cnt++;
            tot++;
        } else {
            if (p[i].first == p[n - 1 - i].first && p[i].second + p[n - i - 1].second >= k) tot++;
            break;
        }
    }
    if (cnt == n) {
        ans -= sum * (m - m % 2);
    } else if (n & 1) {
        if (cnt == n / 2) {
            ans -= (m - 1) * k * cnt;
            ll now = p[n / 2].second;
            now *= m;
            if (now % k == 0) {
                ans = 0;
            } else {
                ans -= now - now % k;
            }
        } else {
            ans -= (m - 1) * k * tot;
        }
    } else {
        ans -= (m - 1) * k * tot;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}