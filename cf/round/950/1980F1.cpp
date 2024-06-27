#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> p(k);
    for(int i=0;i<k;i++)cin>>p[i].first>>p[i].second;
    vector<int> nums(k);
    for(int i=0;i<k;i++)nums[i]=i;
    sort(nums.begin(),nums.end(),[&](int a,int b){
        return p[a]<p[b];
    });
    vector<int> v(k);
    stack<int> stk;
    for(int i:nums){
        if(stk.empty()){
            stk.push(i);
            v[i]=1;
            continue;
        }
        while(!stk.empty()&&p[i].second<=p[stk.top()].second){
            v[stk.top()]=0;
            stk.pop();
        }
        if(stk.empty()||p[stk.top()].first<p[i].first){
            stk.push(i);
            v[i]=1;
        }
    }
    ll ans=0;
    ll x=1,y=1;
    for(int i:nums){
        if(!v[i])continue;
        ans+=(p[i].first-x+1)*(p[i].second-1);
        x=p[i].first+1;
    }
    ans+=(n-x+1)*(m);
    cout<<ans<<endl;
    for(int i=0;i<k;i++){
        cout<<v[i]<<' ';
    }
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