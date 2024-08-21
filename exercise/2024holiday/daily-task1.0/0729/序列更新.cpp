#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> inline void read(T &x) {
    x=0; char ch=getchar(); bool f=0;
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch^48);
    if(f) x=-x;
}
template<class T, class... V>
inline void read(T &a, V &... b){read(a); read(b...);}

void solve() {
    int n, q;
    read(n);
    read(q);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) read(a[i]);
    for (int i = 0; i < n; i++) read(b[i]);
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += a[i];

    int cnt = min(q, 1000);
    q -= cnt;
    while (cnt--) {
        int k;
        read(k);
        for (int i = 0; i < n; i++) {
            ans += max(a[i], b[(i + k) % n]) - a[i];
            a[i] = max(a[i], b[(i + k) % n]);
        }
        // printf("%lld\n", ans);  
    }

    vector<ll> dif(q + 1);
    map<int, int> mp;
    for (int i = 0; i < q; i++) {
        int k;
        read(k);
        if (mp.count(k)) continue;
        else mp[k] = i;
    }
    
    vector<int> tmp(n), nums(n);
    for (int i = 0; i < n; i++) tmp[i] = b[i], nums[i] = i;
    sort(tmp.begin(), tmp.end());
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        return b[x1] < b[x2];
    });
    vector<int> stk(n);
    vector<int> c(n);
    int l = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(tmp.begin(), tmp.end(), a[i]);
        int p = it - tmp.begin();
        c[0] = a[i];
        l = 0;
        while (p < n) {
            int k = (nums[p] - i + n) % n;
            if (!mp.count(k)) {
                p++;
                continue;
            }
            int j = mp[k];
            while (l && j < stk[l]) l--;
            stk[++l] = j;
            c[l] = tmp[p];
            p++;
        }
        for (int j = l; j > 0; j--) {
            dif[stk[j]] += c[j] - c[j - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        ans += dif[i];
        // printf("%lld\n", ans);  
    }
}

int main() {
    int T;
    read(T);
    while (T--) {
        solve();
    }
    return 0;
}