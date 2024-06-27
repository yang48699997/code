#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
ll n,k;
ll gcd(ll x,ll y){
    while(y){
        ll temp=y;
        y=x%y;
        x=temp;
    }
    return x;
}
ll cal(ll x,ll y){
    if(x<y)swap(x,y);
    ll cur=x-y;
    if(cur%k!=0)return -1;
    return cur/k;
}
void solve(){
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<ll,vector<int>> mp;
    for(int i=0;i<n;i++){
        mp[a[i]%k].push_back(a[i]/k);
    } 
    ll ans=0;
    int cnt=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        vector<int> p=it->second;
        sort(p.begin(),p.end());
        if(p.size()%2==1){
            cnt++;
            if(cnt>1){
                cout<<-1;
                return;
            }else{
                if(p.size()==1)continue;
                vector<ll> pre(p.size()/2+1);
                vector<ll> suf(p.size()/2+1);
                for(int i=1;i<p.size();i+=2){
                    pre[i/2+1]=pre[i/2]+p[i]-p[i-1];
                }
                for(int i=p.size()-2;i>=0;i-=2){
                    suf[i/2]=suf[i/2+1]+p[i+1]-p[i];
                }
                ll res=1e18;
                for(int i=0;i<p.size()/2+1;i++)res=min(pre[i]+suf[i],res);
                ans+=res;
            }
            continue;
        }
        for(int i=0;i<p.size();i+=2){
            ans+=p[i+1]-p[i];
        }
    }
    cout<<ans;
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