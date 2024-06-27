#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef  long long ull;
const ull p=33951943;
const ull mod1=1e9+7;
const ull mod2=1<<30;
using pll=pair<ull,ull>;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    pll l=make_pair(0,0),r=make_pair(0,0);
    vector<ull> f1(n+1,1);
    vector<ull> f2(n+1,1);
    for(int i=1;i<=n;i++)f1[i]=f1[i-1]*p%mod1;
    for(int i=1;i<=n;i++)f2[i]=f2[i-1]*p%mod2;
    for(int i=0;i<n;i++){
        l.first*=p;
        l.second*=p;
        l.first+=s[i];
        l.second+=s[i];
        l.first%=mod1;
        l.second%=mod2;
    }
    for(int i=n*2-1;i>=n;i--){
        r.first*=p;
        r.second*=p;
        r.first+=s[i];
        r.second+=s[i];
        r.first%=mod1;
        r.second%=mod2;
    }
    if(l==r){
        for(int i=n-1;i>=0;i--)cout<<s[i];
        cout<<endl;
        cout<<0;
        return;
    }
    for(int i=1;i<=n;i++){
        l.first-=f1[n-1]*(s[i-1])%mod1;
        l.second-=f2[n-1]*(s[i-1])%mod2;
        l.first%=mod1;
        if(l.first<0)l.first+=mod1;
        l.first*=p;
        l.second*=p;
        l.second%=mod2;
        if(l.second<0)l.second+=mod2;
        l.first+=s[i+n-1];
        l.second+=s[i+n-1];
        r.first+=f1[i-1]*(s[i-1])%mod1;
        r.second+=f2[i-1]*(s[i-1])%mod2;
        r.first-=f1[i-1]*(s[i+n-1])%mod1;
        r.second-=f2[i-1]*(s[i+n-1])%mod2;
        l.first%=mod1;
        l.second%=mod2;
        r.first%=mod1;
        r.second%=mod2;
        if(l.first<0)l.first+=mod1;
        if(r.first<0)r.first+=mod1;
        if(l.second<0)l.second+=mod2;
        if(r.second<0)r.second+=mod2;
        if(l==r){
            for(int j=i+n-1;j>=i;j--)cout<<s[j];
            cout<<endl;
            cout<<i;
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