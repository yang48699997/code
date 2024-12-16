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
    int n, k;
    cin >> n >> k >> seed;

    vector<int> a(k);
    vector<int> v(n + 1);
    for (int i = 0; i < k; i++) {
        a[i] = rnd() % n + 1;
        v[a[i]]++;
    }

    vector<int> dif(n + 2);
    vector<int> L(n + 1), R(n + 1); 
    vector<int> cnt(n + 1);

    int l = 0, r = n + 1;
    for (int i = 1; i <= n; i++) {
        if (v[i]) {
            L[i] = l;
            l = i;
            cnt[i] = v[i];
        }
        
    }
    for (int i = n; i > 0; i--) {
        if (v[i]) {
            R[i] = r;
            r = i;
        }
    }

    for (int i = k - 1; i > 0; i--) {
        cnt[a[i]]--;

        if (cnt[a[i]]) {
            continue;
        } else {
            l = L[a[i]];
            r = R[a[i]];
            if (l == 0) {
                dif[1]--;
                dif[r]++;
                L[r] = 0;
            } else if (r == n + 1) {
                dif[l + 1]--;
                R[l] = n + 1;
            } else {
                dif[l + 1]--;
                dif[r]++;
                R[l] = r;
                L[r] = l;
            }
        }
    }


    int mx = -1e9;
    for (int i = 1; i <= n; i++) {
        dif[i] += dif[i - 1];
        if (v[i]) continue;
        mx = max(mx, dif[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (v[i]) continue;
        if (mx == dif[i]) {
            cout << i << "\n";
            return;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}