#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(n),c(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<m;i++)cin>>c[i];
    ll ans=0;
    vector<int> nums(n);
    for(int i=0;i<n;i++)nums[i]=i;
    sort(nums.begin(),nums.end(),[&](int x,int y){
        return a[x]-b[x]<a[y]-b[y];
    });
    vector<pair<int,int>> stk;
    for(int i:nums){
        while(!stk.empty()){
            auto [t,d]=stk.back();
            if(a[i]-b[i]<=d&&a[i]<=t)stk.pop_back();
            else break;
        }
        if(stk.empty())stk.push_back({a[i],a[i]-b[i]});
        else if(a[i]<stk.back().first)stk.push_back({a[i],a[i]-b[i]});
    }
    reverse(stk.begin(),stk.end());
    // for(int i=0;i<stk.size();i++){
    //     cerr<<stk[i].first<<' '<<stk[i].second<<endl;
    // }
    // cerr<<endl;
    int mx=1e6+5;
    vector<ll> dp(mx,-1);
    auto dfs=[&](auto &&self,int x)->ll{
        if(dp[x]!=-1)return dp[x];
        auto it=upper_bound(stk.begin(),stk.end(),make_pair(x,mx));
        it--;
        int t=it->first;
        int d=it->second;
        ll res=0;
        ll ans=0;
        res+=(x-t)/d+1;
        ans+=res*2;
        ans+=self(self,x-res*d);
        dp[x]=ans;
        return ans;
    };
    for(int i=0;i<stk[0].first;i++)dp[i]=0;
    for(int i=0;i<m;i++){
        ll res=0;
        if(c[i]>stk.back().first){
            res+=(c[i]-stk.back().first)/stk.back().second+1;
            c[i]-=res*stk.back().second;
        }
        ans+=res*2;
        ans+=dfs(dfs,c[i]);
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    T=1;
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}