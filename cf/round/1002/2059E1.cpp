#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    int N = n * m;
    vector<int> a(N), v(N * 2, -1);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x--;
        v[x] = i;
    }

    int ans = N;
    int p = 0, last = -1;

    for (int i = 0; i < N; i++) {
        if (v[a[i]] <= last) break;

        if (last + 1 == v[a[i]] || i % m == 0 || i / m != (last + 1) / m) {
            p++;
        } else break;

        last = v[a[i]];
        if ((last + 1) % m == 0 || i / m != last / m) {
            ans -= p;
            p = 0;
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