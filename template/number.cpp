#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> cal_div(ll n) {
    vector<ll> res(1, 1);
    ll cur = n;
    for (ll i = 2; i <= sqrtl(n); i++) {
        if (cur % i) continue;
        int m = res.size();
        ll p = 1;
        while (cur % i == 0) {
            p *= i;
            for (int j = 0; j < m; j++) res.push_back(res[j] * p);
            cur /= i;
        }
    }
    if (cur > 1) {
        int m = res.size();
        for (int i = 0; i < m; i++) res.push_back(cur * res[i]);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {

    // vector<ll> res = cal_div(100LL);
    // for (ll i : res) cout << i << "\n";
    return 0;
}
