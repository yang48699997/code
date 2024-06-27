#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<tuple<int,int,int>> g(k);
    for(int i=0;i<k;i++){
        int x,l,r;
        cin>>x>>l>>r;
        x--;
        g[i]=make_tuple(x,l,r);
    } 
    vector<vector<pair<int,int>>> e(n);
    while(m--){
        int x,y,val;
        cin>>x>>y>>val;
        x--,y--;
        e[x].push_back({y,val});
        e[y].push_back({x,val});
    }
    int pre=0;
    ll ans=-1;
    const ll inf = 1e18;
    for(int i=1;i<=t;i++){
        int cur=0;
        int cnt=0;
        for(auto [p,l,r]:g){
            if(i>=l&&i<=r){
                cur|=1<<cnt;
            }
            cnt++;
        }
        if(cur==pre){
            cout<<ans<<endl;
            continue;
        }
        if(cur==0)ans=-1;
        else{
            vector<ll> d(n,inf);
            vector<int> v(n);
            priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
            for(int j=0;j<k;j++){
                if(cur>>j&1){
                    d[get<0>(g[j])]=0;
                    q.push({0,get<0>(g[j])});
                }
            }
            while(!q.empty()){
                auto [dis,x]=q.top();
                q.pop();
                if(v[x])continue;
                v[x]=1;
                for(auto [nxt,val]:e[x]){
                    if(dis+val<d[nxt]){
                        d[nxt]=dis+val;
                        q.push({d[nxt],nxt});
                    }
                }
            }
            ans=0;
            for(int j=0;j<n;j++){
                ans+=d[j]*a[j];
                // cerr<<d[i]<<" \n"[j==n-1];
            }
        }
        pre=cur;
        cout<<ans<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}