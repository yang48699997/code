/*
 * Author: Ram
 * Date: 2024-05-19
 * Source: https://www.luogu.com.cn/problem/T455123?contestId=172272
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,m,x,y;
    cin>>n>>m;
    vector<int> cnt(n+1);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        cnt[x]++;
        cnt[y]--;
    }
    int res=0,mx=-1;
    for(int i=1;i<=n;i++){
        if(cnt[i]>mx){
            mx=cnt[i];
            res=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i==res){
            cout<<0<<' ';
            continue;
        }cout<<res<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}