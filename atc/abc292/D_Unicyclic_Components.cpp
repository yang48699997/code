#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> fa,size,cnt;
    DSU(int n):fa(n),size(n,1), cnt(n){
        for(int i=0;i<n;i++)fa[i]=i;
    }
    int find(int x){
        if(fa[x]==x)return x;
        fa[x]=find(fa[x]);
        return fa[x];
    }
    bool merge(int x,int y){
        x=find(x);
        y=find(y);
        cnt[x]++;
        if(x==y)return false;
        cnt[x] += cnt[y];
        size[x]+=size[y];
        fa[y]=x;
        return true;
    }
    int getCount(int x){
        x=find(x);
        return size[x];
    }
    int getCount2(int x){
        x=find(x);
        return cnt[x];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu{n};
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        dsu.merge(x, y);
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        if (dsu.getCount(i) != dsu.getCount2(i)) {
            cout << "No\n";
            return;
        } 
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}