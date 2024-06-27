#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int T;
typedef  long long ull;
const ull p=33951943;
const ull mod1=1e9+7;
const ull mod2=1<<30;
using pll=pair<ull,ull>;
const ull d0=19,d1=37;
void solve(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    pll t1=make_pair(0,0),t2=make_pair(0,0);
    vector<ull> f1(n+1,1);
    vector<ull> f2(n+1,1);
    for(int i=1;i<=n;i++)f1[i]=f1[i-1]*p%mod1;
    for(int i=1;i<=n;i++)f2[i]=f2[i-1]*p%mod2;
    for(int i=0;i<n;i++){
        if((i/k)%2){
            t1.first=(t1.first*p+d0)%mod1;
            t1.second=(t1.second*p+d0)%mod2;
            t2.first=(t2.first*p+d1)%mod1;
            t2.second=(t2.second*p+d1)%mod2;
        }else{
            t1.first=(t1.first*p+d1)%mod1;
            t1.second=(t1.second*p+d1)%mod2;
            t2.first=(t2.first*p+d0)%mod1;
            t2.second=(t2.second*p+d0)%mod2;
        }
    }
    pll cur=make_pair(0,0);
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cur.first=(cur.first*p+d0)%mod1;
            cur.second=(cur.second*p+d0)%mod2;
        }else{
            cur.first=(cur.first*p+d1)%mod1;
            cur.second=(cur.second*p+d1)%mod2;
        }
    }
    pll lef=make_pair(0,0);
    for(int i=0;i<n;i++){
         pll now=make_pair(f1[n-1],f2[n-1]);
         if(s[i]=='0'){
            now.first=(now.first*d0)%mod1;
            now.second=(now.second*d0)%mod2;
         }else{
            now.first=(now.first*d1)%mod1;
            now.second=(now.second*d1)%mod2;
         }
         cur.first-=now.first;
         cur.first%=mod1;
         if(cur.first<0)cur.first+=mod1;
         cur.second-=now.second;
         cur.second%=mod2;
         if(cur.second<0)cur.second+=mod2;
         now=lef;
         cur.first-=now.first;
         cur.first%=mod1;
         if(cur.first<0)cur.first+=mod1;
         cur.second-=now.second;
         cur.second%=mod2;
         if(cur.second<0)cur.second+=mod2;
         cur.first=(cur.first*p)%mod1;
         cur.second=(cur.second*p)%mod2;
         if(s[i]=='0'){
            lef.first=(lef.first+f1[i]*d0)%mod1;
            lef.second=(lef.second+f2[i]*d0)%mod2;
         }else{
            lef.first=(lef.first+f1[i]*d1)%mod1;
            lef.second=(lef.second+f2[i]*d1)%mod2;
         }
         cur.first=(cur.first+lef.first)%mod1;
         cur.second=(cur.second+lef.second)%mod2;
         if(cur==t1||cur==t2){
            cout<<i+1;
            return;
         }
    }
    cout<<-1;
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