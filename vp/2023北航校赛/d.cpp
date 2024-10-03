#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> val;
    int l = 0;
    while (l < n && a[l] == 0) {
        val.push_back(0);
        l++;
    }
    val.push_back(a[l]);
    ll p0 = a[l], p1 = 0;
    if (p0 < 0) swap(p0, p1);
    for (int i = l + 1; i < n; i++) {
        val.push_back(p0 + a[i]);
        val.push_back(p1 + a[i]);
        p1 += a[i];
        p0 += a[i];
        if (p0 < 0) {
            p1 = p0;
            p0 = 0;
        } else if (p0 > 0 && p1 < 0) {
            p1 = 0;
        }
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    cout << val[val.size() - 2] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}