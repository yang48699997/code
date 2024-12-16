#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int N = 27;
    vector<unordered_map<int, ll>> tot(N);
    vector<unordered_map<int, int>> cnt(N);
    for (int i = 0; i < n; i++) {
        int now = 1;
        for (int j = 0; j < N; j++) {
            tot[j][a[i] % now] += a[i];
            cnt[j][a[i] % now]++;
            now *= 2;
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int now = 1;
        for (int j = 0; j < N; j++) {
            now *= 2;
        }

        ll pre = 0, psum = 0;
        for (int j = N - 1; j >= 0; j--) {
            now /= 2;
            int p = a[i] % now;
            if (p != 0) p = now - p;
            
            auto it = cnt[j].find(p);
            if (it == cnt[j].end()) {
                continue;
            }

            ll c = it -> second;
            ll sum = tot[j][p];

            ans += ((c - pre) * a[i] + sum - psum) / now; 
            pre = c;
            psum = sum;
        }
        
        now = 1;
        for (int j = 0; j < N; j++) {
            tot[j][a[i] % now] -= a[i];
            cnt[j][a[i] % now]--;
            now *= 2;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}