#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> p;
const int mx = 1e5;

void init() {
    vector<int> v(mx);
    p.clear();

    for (int i = 2; i < mx; i++) {
        if (!v[i]) p.push_back(i);
        for (int j = 0; p[j] * i < mx; j++) {
            v[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll cnt = 0;
    ll sum = 0;

    if (*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end())) {
        cnt = k;
        sum = cnt * (cnt + 1) / 2;
    } else {
        
        ll dif = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
        int m = p.size();
        vector<ll> divs(1, 1);

        for (int i = 0; i < m; i++) {
            if (dif % p[i]) continue;
            vector<int> div;
            int pp = 1;
            while (dif % p[i] == 0) {
                pp *= p[i];
                dif /= p[i];
                div.push_back(pp);
            }
            int now = divs.size();
            for (int d : div) {
                for (int q = 0; q < now; q++) {
                    divs.push_back(divs[q] * d);
                }
            }
        }
        if (dif > 1) {
            int now = divs.size();
            for (int i = 0; i < now; i++) {
                divs.push_back(divs[i] * dif);
            }
        }
        for (int d : divs) {
            int ok = 1;
            int x = d - *min_element(a.begin(), a.end());
            if (x < 1 || x > k) continue;
            for (int i = 1; i < a.size(); i++) {
                if ((a[i] + x) % (a[i - 1] + x) && (a[i - 1] + x) % (a[i] + x)) {
                    ok = 0;
                    break;
                }
            }
            cnt += ok;
            sum += ok * x;
        }
    }

    cout << cnt << " " << sum << "\n";
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