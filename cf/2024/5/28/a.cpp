#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
const int mod=19930726;

ll powMod(ll x,ll p){
    ll res=1;
    while(p){
        if(p&1)res=res*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return res;
}
void solve(){
    int m;
    string ss;
    ll k;
    cin>>m>>k>>ss;
    string s="!";
    for(int i=0;i<ss.length();i++){
        s+="#";
        s+=ss[i];
    }
    s+="#%";
    int n=s.length();
    vector<int> cnt(n);
    vector<int> p(n);
    int c=0,r=0;
    for(int i=1;i<n-1;i++){
        int i_mir=2*c-i;
        if(r>i)p[i]=min(p[i_mir],r-i);
        while(s[i+1+p[i]]==s[i-1-p[i]])p[i]++;
        if(p[i]+i>r)r=p[i]+i,c=i;
        cnt[p[i]]++;
    }
    ll ans=1;
    ll cur=0;
    for(int i=n-1;i>0;i-=2){
        if(i%2==0)i--;
        cur+=cnt[i];
        ll p = min(k,cur);
        k-=p;
        ans=ans*powMod(i,p)%mod;
        if(k==0){
            cout<<ans;
            return;
        }
    }
    cout<<-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}