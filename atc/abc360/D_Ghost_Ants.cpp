#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    vector<int> x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    vector<ll> l,r;
    for(int i=0;i<n;i++){
        if(s[i]=='1')l.push_back(x[i]);
        else r.push_back(x[i]);
    }
    int inf=2e9;
    r.push_back(-inf);
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    ll ans=0;
    for(int i=0;i<l.size();i++){
        auto it=lower_bound(r.begin(),r.end(),l[i]);
        it--;
        auto it2=upper_bound(r.begin(),r.end(),l[i]+t*2);
        it2--;

        int res=it2-it;
        ans+=res;
        // cerr<<res<<endl;
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