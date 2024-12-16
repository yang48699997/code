#include <bits/stdc++.h>
using namespace std;

using ll = unsigned;

ll seed;

ll rnd() {
	ll ret = seed;
	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	return ret;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k >> seed;

    vector<vector<long long>> g(n, vector<long long> (m)); 
    vector<vector<int>> pend(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pend[j].push_back(i);
        }
    }

    for (int i = 0; i < k; i++) {
        int op = rnd() % 2 + 1;

        if (op == 1) {
            int j = rnd() % m;
            int x = rnd() % (n * m) + 1;
            for (int p : pend[j]) {
                g[p][j] = x;
            }
            pend[j].clear();
        } else {
            int a = rnd() % n;
            int b = rnd() % m;
            g[a][b] = 0;
            pend[b].push_back(a);
        }
    }


    long long ans = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt++;
            ans ^= cnt * g[i][j];
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