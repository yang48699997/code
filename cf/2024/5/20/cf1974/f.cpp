/*
 * Author: Ram
 * Date: 2024-05-20
 * Source: https://codeforces.com/contest/1974/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int a,b,n,m;
    cin>>a>>b>>n>>m;
    vector<int> cnt(2);
    map<pair<int,int>,int> xp,yp;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        xp[{x,y}]++;
        yp[{y,x}]++;
    }
    int l=0,r=a+1,d=0,u=b+1;
    char c;
    int k,cur=0;
    while(m--){
        cin>>c>>k;
        if (c == 'R') {  // 向上移动喵
            u -= k;
            auto it = yp.lower_bound({u, 0});
            while (it != yp.end() && it->first.first >= u) {
                cnt[cur] += it->second;
                x = it->first.second;
                xp.erase({x, it->first.first});
                it = yp.erase(it);
            }
            cur ^= 1;
        } else if (c == 'L') {  // 向下移动喵
            d += k;
            auto it = yp.upper_bound({d, INT_MAX});
            auto start = yp.begin();
            while (start != it) {
                cnt[cur] += start->second;
                x = start->first.second;
                xp.erase({x, start->first.first});
                start = yp.erase(start);
            }
            cur ^= 1;
        } else if (c == 'U') {  // 向左移动喵
            l += k;
            auto it = xp.upper_bound({l, INT_MAX});
            auto start = xp.begin();
            while (start != it) {
                cnt[cur] += start->second;
                y = start->first.second;
                yp.erase({y, start->first.first});
                start = xp.erase(start);
            }
            cur ^= 1;
        } else {  // 向右移动喵D
            r -= k;
            auto it = xp.lower_bound({r, 0});
            while (it != xp.end() && it->first.first >= r) {
                cnt[cur] += it->second;
                y = it->first.second;
                yp.erase({y, it->first.first});
                it = xp.erase(it);
            }
            cur ^= 1;
        }
    }
    cout<<cnt[0]<<' '<<cnt[1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}