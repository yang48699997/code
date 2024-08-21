#include <bits/stdc++.h>
using namespace std;
 
long long T;
void solve() {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    map<long long,long long> cnt;
    long long cur = x;
    for (long long i = 2; i <= sqrt(x); i++) {
        if (cur % i) continue;
        while (cur % i == 0) {
            cnt[i]++;
            cur /= i;
        }
    }
    if (cur > 1) cnt[cur]++;
    vector<long long> v(1,1);
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        long long xx = it->first;
        long long p = it->second;
        for (long long i = 0; i < p; i++) {
            long long m = v.size();
            for (long long j = 0; j < m; j++) v.push_back(v[j] * xx);
            sort(v.begin(), v.end());
            long long mm = unique(v.begin(),v.end()) - v.begin();
            v.resize(mm);
        }
    }
    long long m = v.size();
    vector<long long> p(m);
    p[0] = 1;
    long long ans = 1;
    for (long long i = 0; i < n; i++) {
        long long xx = a[i];
        if (x % xx) continue;
        vector<long long> temp;
        for (long long j = 0; j < m; j++) {
            if (!p[j]) continue;
            temp.push_back(v[j] * xx);
        }
        long long l = 0;
        for (long long j = 0; j < m; j++) {
            while (l < temp.size() && temp[l] < v[j]) l++;
            if (l == temp.size()) break;
            if (v[j] == temp[l]) {
                p[j] = 1;
                l++;
                if (l == temp.size()) break;
            }
        }
        if (p.back()) {
            ans++;
            for (long long j = 0; j < m; j++) {
                p[j] = 0;
                if (j == 0 || v[j] == xx) p[j] = 1;
            }
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}