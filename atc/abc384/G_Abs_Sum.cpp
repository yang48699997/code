#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<pair<ll, ll>> a;
    Fenwick(int x) : n(x), a(x + 1) {};
    void build() {
        for (int i = 1; i <= n; i++) {
            int nxt = i + (i & -i);
            if (nxt <= n) {
                a[nxt].first += a[i].first;
                a[nxt].second += a[i].second;
            }
        }
    }
    pair<ll, ll> query(int x) {
        pair<ll, ll> res = {0, 0};
        while (x) {
            res.first += a[x].first;
            res.second += a[x].second;
            x -= (x & -x);
        }
        return res;
    }
    void update(int x, pair<ll, ll> val) {
        while (x <= n) {
            a[x].first += val.first;
            a[x].second += val.second;
            x += (x & -x);
        }
        return;
    }
};

using F = Fenwick;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    vector<int> p(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        p[n + i] = b[i];
    }

    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int N = p.size();
    map<int, int> ref;
    for (int i = 0; i < p.size(); i++) {
        ref[p[i]] = i + 1; 
    }
    F f1(N), f2(N);

    int q;
    cin >> q;
    vector<array<int, 2>> ask(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i][0] >> ask[i][1]; 
        ask[i][0]--;
        ask[i][1]--;
    }

    vector<int> A(q);
    iota(A.begin(), A.end(), 0);

    int block = n / sqrt(q) + 1;
    sort(A.begin(), A.end(), [&](int x1, int x2) {
        if (ask[x1][0] / block != ask[x2][0] / block) return ask[x1][0] / block < ask[x2][0] / block;
        return (ask[x1][0] / block % 2) ? (ask[x1][1] < ask[x2][1]) : (ask[x1][1] > ask[x2][1]);
    });

    vector<ll> ans(q);
    int l = -1, r = -1;

    ll sum1 = 0, cnt1 = 0;
    ll sum2 = 0, cnt2 = 0;
    ll res = 0;
    for (int i : A) {
        int cl = ask[i][0];
        int cr = ask[i][1];

        while (l > cl) {
            int now = a[l--];
            int t = ref.find(now) -> second;
            auto [cnt, sum] = f2.query(t);
            res -= cnt * now - sum;
            res -= sum2 - sum - (cnt2 - cnt) * now;
            cnt1--;
            sum1 -= now;
            f1.update(t, {-1, -now});
        }
        while (r < cr) {
            int now = b[++r];
            int t = ref.find(now) -> second;
            auto [cnt, sum] = f1.query(t);
            res += cnt * now - sum;
            res += sum1 - sum - (cnt1 - cnt) * now;
            cnt2++;
            sum2 += now;
            f2.update(t, {1, now});
        }
        while (l < cl) {
            int now = a[++l];
            int t = ref.find(now) -> second;
            auto [cnt, sum] = f2.query(t);
            res += cnt * now - sum;
            res += sum2 - sum - (cnt2 - cnt) * now;
            cnt1++;
            sum1 += now;
            f1.update(t, {1, now});
        }
        while (r > cr) {
            int now = b[r--];
            int t = ref.find(now) -> second;
            auto [cnt, sum] = f1.query(t);
            res -= cnt * now - sum;
            res -= sum1 - sum - (cnt1 - cnt) * now;
            cnt2--;
            sum2 -= now;
            f2.update(t, {-1, -now});
        }

        ans[i] = res;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}