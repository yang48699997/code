/*
 * Author: Ram
 * Date: 2024-04-11
 * Source: https://codeforces.com/gym/105053/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> st(n+1),ed(n+1);
    vector<int> a(n*2);
    for(int i=0;i<n*2;i++){
        int x;
        cin>>x;
        a[i]=x;
        if(x>0)st[x]=i;
        else ed[-x]=i;
    }
    vector<vector<int>> e(n+1);
    for(int i=1;i<=n;i++){
        int x1=st[i],y1=ed[i];
        for(int j=1;j<=n;j++){
            int x2=st[j],y2=ed[j];
            bool k1=(x1<x2&&x2<y1);
            bool k2=(x1<y2&&y2<y1);
            if(k1&&k2);
            else if(!k1&&!k2);
            else e[i].push_back(j);
        }
    }
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        if(v[i])continue;
        queue<pair<int,int>> q;
        q.push({i,1});
        v[i]=1;
        while(!q.empty()){
            auto [x,c]=q.front();
            q.pop();
            for(int nxt:e[x]){
                if(v[nxt]&&v[nxt]!=(c^3)){
                    cout<<"*";
                    return;
                }else if(v[nxt])continue;
                v[nxt]=c^3;
                q.push({nxt,v[nxt]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]==1)cout<<"G";
        else cout<<"S";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<'\n';
    return 0;
}