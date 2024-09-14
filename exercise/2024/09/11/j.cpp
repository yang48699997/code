#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 5;

int tot;
int v[N], p[N];

void init() {
    tot = 0;
    for (int i = 0; i < N; i++) {
        v[i] = 0;
    }
    for (int i = 2; i < N; i++) {
        if (!v[i]) {
            p[tot++] = i;
        }
        for (int j = 0; i * p[j] < N; j++) {
            v[i * p[j]] = 1;
            if (i % p[j] == 0) break; 
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (!v[sum]) continue;
            if (ans == -1) ans = j - i;
            else ans = min(ans, j - i);
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