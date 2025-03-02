#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
vector<int> p;
int v[N], q[N];

void init() {
    p.clear();
    v[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!v[i]) {
            p.push_back(i);
        }
        for (int j = 0; i * p[j] < N; j++) {
            v[i * p[j]] = 1;
            q[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cnt[x]++;
    }

    ll ans = 0;

    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            sum += cnt[i];
            ans += 1LL * cnt[i] * (sum - cnt[i]);
        } else if (!v[i / q[i]]) {
            ans += 1LL * cnt[i] * (cnt[i] + 1) / 2;
            ans += 1LL * cnt[i] * cnt[q[i]];
            if (i / q[i] != q[i]) ans += 1LL * cnt[i] * cnt[i / q[i]];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}