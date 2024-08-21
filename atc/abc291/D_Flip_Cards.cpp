#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }    
    ll sum1 = 1, sum2 = 1;
    int pre1 = a[0], pre2 = b[0];
    for (int i = 1; i < n; i++) {
        ll res1 = 0, res2 = 0;
        if (a[i] != pre1) {
            res1 = (res1 + sum1) % mod;
        }
        if (b[i] != pre1) {
            res2 = (res2 + sum1) % mod;
        }
        if (a[i] != pre2) {
            res1 = (res1 + sum2) % mod;
        }
        if (b[i] != pre2) {
            res2 = (res2 + sum2) % mod;
        }
        sum1 = res1;
        sum2 = res2;
        pre1 = a[i];
        pre2 = b[i];
    }
    cout << (sum1 + sum2) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}