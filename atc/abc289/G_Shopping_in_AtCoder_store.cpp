#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> b(n),c(m);
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<m;i++)cin>>c[i];
    sort(b.rbegin(),b.rend());
    for(int i=0;i<n;i++)b[i]=b[i]*(i+1);
    stack<ll> stk;
    auto cross=[&](ll a1,ll a2,ll a3)->ll{
        ll x1=a3-a1,x2=a2-a1;
        ll y1=b[a3]-b[a1],y2=b[a2]-b[a1];
        return x1*y2-x2*y1;
    };
    for(ll i=0;i<n;i++){
        while(stk.size()>1){
            ll tp=stk.top();
            stk.pop();
            ll res=cross(stk.top(),tp,i);
            if(res>0){
                stk.push(tp);
                break;
            }
        }
        stk.push(i);
    }
    vector<ll> con;
    while(!stk.empty()){
        con.emplace_back(stk.top());
        stk.pop();
    }
    reverse(con.begin(),con.end());
    for(auto q:c){
        int l=0,r=con.size()-2;
        ll ans=0;
        while(l<=r){
            int mid=(r-l)/2+l;
            ll x=con[mid+1]-con[mid];
            ll y=b[con[mid+1]]-b[con[mid]];
            ll res=y+q*x;
            if(res>0)l=mid+1;
            else r=mid-1;
        }
        ans=max((con[l]+1)*q+b[con[l]],ans);
        if(l+1<con.size()){
            l++;
            ans=max((con[l]+1)*q+b[con[l]],ans);
        }
        cout<<ans<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}