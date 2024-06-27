#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
int n,m;
vector<int> p;
vector<int> mul;

ll lcm(ll x,ll y){
    while(y!=0){
        ll temp=y;
        y=x%y;
        x=temp;
    }
    return x;
}
const int N=2e5+5;
int tot;
int pp[N];
void f(int x,int cur){
    if(x==m){
        pp[++tot]=cur;
        return;
    }
    int nxt=1;
    for(int i=0;i<=p[x];i++){
        f(x+1,cur*nxt);
        nxt*=mul[x];
    }
    
}
void solve(){
    cin>>n;
    vector<ll> a(n);
    set<ll> st;
    for(int i=0;i<n;i++)cin>>a[i],st.insert(a[i]);
    bool ok=true;
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
        if(a[n-1]%a[i]!=0){
            ok=false;
            break;
        }
    }
    if(!ok){
        cout<<n;
        return;
    }
    int mx=a.back();
    p.clear();
    mul.clear();
    for(int i=2;i<=sqrt(a.back());i++){
        if(mx%i)continue;
        int cnt=0;
        mul.push_back(i);
        while(mx%i==0){
            cnt++;
            mx/=i;
        }
        p.push_back(cnt);
    }
    if(mx>1){
        p.push_back(1);
        mul.push_back(mx);
    }
    int ans=0;
    tot=0;
    m=p.size();
    f(0,1);
    for(int i=1;i<=tot;i++){
        // cout<<pp[i]<<' ';
        if(st.count(pp[i]))continue;
        ll cur=1;
        int cnt=0;
        for(int j=0;j<n;j++){
            if(pp[i]%a[j]==0){
                cur=cur/lcm(cur,a[j])*a[j];
                cnt++;
            }
        }
        if(cur==pp[i])ans=max(ans,cnt);
    }
    cout<<ans;
    // cout<<endl<<" p:"<<endl;
    // for(int i=0;i<p.size();i++)cout<<p[i]<<' '<<mul[i]<<endl;
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