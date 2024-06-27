/*
 * Author: Ram
 * Date: 2024-05-14
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int mod=998244353;
int powMod(ll x){
    ll res=1;
    int y=mod-2;
    while(y){
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n*2);
    for(int i=0;i<n*2;i++)cin>>a[i];
    map<int,int> mp;
    int cnt=0;
    ll ans=1,mx=-1,tot=0;
    for(int i=0;i<n*2;i++){
        if(a[i]>=0){
            mp[a[i]]++;
            tot++;
        }else{
            auto it=mp.begin();
            int x=it->first;
            if(x<mx){
                cout<<0;
                return ;
            }
            mx=x;
            int cnt=it->second;
            ans=ans*cnt%mod*powMod(tot)%mod;
            cnt--;
            tot--;
            if(cnt==0)mp.erase(it);
            else mp[x]--;
        }
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}