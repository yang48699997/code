#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    map<int, int> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x -= i;
        p[i] = x;
    }

    ll ans = 0;

    int q;
    cin >> q;
    
    while (q--) {
        int t, x;
        cin >> t >> x;
        t--;
        x -= t;

        auto it = prev(p.upper_bound(t));
        int now = it->second;

        if (now < x) {
            p[t] = now;
            it = p.find(t);

            while (1) {
                auto nxt = next(it);
                if (nxt == p.end()) {
                    ans += 1LL * (n - t) * (x - now);
                    break;
                }
                if (nxt->second > x) {
                    ans += 1LL * (nxt->first - t) * (x - now);
                    break;
                }
                ans += 1LL * (nxt->first - t) * (nxt->second - now);
                now = nxt->second;
                p.erase(nxt);
            }
            it->second = x;
        } else if (now > x) {
            if (t != n - 1 && (next(it) == p.end() || next(it)->first != t + 1)){
                p[t + 1] = now;
            }
            while (true) {
                if (it == p.begin()) {
                    ans += 1LL * (t - it->first + 1) * (now - x);
                    break;
                }
                auto pre = prev(it);
                if (pre->second < x) {
                    ans += 1LL * (t - it->first + 1) * (now - x);
                    break;
                }
                ans += 1LL * (t - it->first + 1) * (now - pre->second);
                now = pre->second;
                p.erase(it);
                it = pre;
            }
            it->second = x;
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