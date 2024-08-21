#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU{
    vector<int> fa,l, r;
    DSU(int n):fa(n),l(n), r(n){
        for(int i=0;i<n;i++)fa[i] = l[i] = r[i] =i;
    }
    int find(int x){
        if(fa[x]==x)return x;
        fa[x]=find(fa[x]);
        return fa[x];
    }
    bool merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return false;
        l[x] = min(l[x], l[y]);
        r[x] = max(r[x], r[y]);
        fa[y]=x;
        return true;
    }
    int count(int i) {
        i = find(i);
        return r[i] - l[i] + 1;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> l(q), r(q), c(q);
    vector<int> nums(q);
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> c[i];
        nums[i] = i;
    }

    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        return c[x1] < c[x2];
    });

    ll ans = 0;
    int ok = 1;

    DSU dsu(n + 1);

    for (int i : nums) {
        ll cl = l[i], cr = r[i], cc = c[i];
        int f = dsu.find(cl);
        ans += cc;
        while (dsu.r[f] < cr) {
            dsu.merge(f, dsu.r[f] + 1);
            ans += cc;
        }
    }
    if (dsu.count(1) != n) ok = 0; 
    cout << (ok == 0 ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}