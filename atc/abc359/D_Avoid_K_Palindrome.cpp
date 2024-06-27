#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int mod=998244353;
using ll = long long;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans=0;
    vector<int> p(n+1,1);
    for(int i=1;i<=n;i++)p[i]=p[i-1]*2%mod;
    vector<int> re(1<<k);
    for(int i=1;i<1<<k;i++){
        re[i]=(re[i/2]+(i%2==1?(1<<k):0))/2;
    }
    vector<int> cnt(1<<k);
    queue<int> q;
    q.push(0);
    for(int i=0;i<k;i++){
        int sz=q.size();
        for(int j=0;j<sz;j++){
            int cur=q.front();
            q.pop();
            if(s[i]!='B')q.push(cur*2);
            if(s[i]!='A')q.push(cur*2+1);
        }
    }
    while(!q.empty()){
        int cur=q.front();
        cnt[cur]++;
        q.pop();
    }
    vector<int> nxt(1<<k);
    for(int i=k;i<n;i++){
        for(int j=0;j<1<<k;j++)nxt[j]=0;
        if(s[i]!='B'){
            for(int j=0;j<1<<k;j++){
                if(re[j]==j)cnt[j]=0;
                else{
                    int res=(j<<1&((1<<k)-1));
                    nxt[res]=(nxt[res]+cnt[j])%mod;
                }
            }
        }
        if(s[i]!='A'){
            for(int j=0;j<1<<k;j++){
                if(re[j]==j)cnt[j]=0;
                else{
                    int res=((j*2+1)&((1<<k)-1));
                    nxt[res]=(nxt[res]+cnt[j])%mod;
                }
            }
        }
        cnt=nxt;
    }
    for(int i=0;i<1<<k;i++){
        if(re[i]==i)continue;
        ans=(ans+cnt[i])%mod;
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