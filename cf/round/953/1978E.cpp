#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e5+5;
int T;
int a[N],b[N];
int tr1[N],tr2[N];
int n;
void build1(){
    for(int i=1;i<=n;i++)tr1[i]=0;
    for(int i=1;i<=n;i++){
        tr1[i]+=a[i];
        int nxt=i+(i&-i);
        if(nxt<=n)tr1[nxt]+=tr1[i];
    }
}
void build2(){
    for(int i=1;i<=n;i++)tr2[i]=0;
    for(int i=1;i<=n;i++){
        tr2[i]+=b[i];
        int nxt=i+(i&-i);
        if(nxt<=n)tr2[nxt]+=tr2[i];
    }
}
int query1(int l){
    int res=0;
    for(;l;l-=l&-l)res+=tr1[l];
    return res;
}
int query2(int l,int r){
    if(l>r)return 0;
    int res=0;
    for(;r;r-=r&-r)res+=tr2[r];
    l--;
    for(;l;l-=l&-l)res-=tr2[l];
    return res;
}
void solve(){
    int q;
    string s,t;
    cin>>n>>s>>t>>q;
    s='#'+s;
    t='#'+t;
    string tt="#";
    for(int i=1;i<=n;i++){
        if(t[i]=='1')tt+='1';
        else if(i>1&&i<n&&s[i-1]=='0'&&s[i+1]=='0')tt+='1';
        else tt+='0';
    }
    for(int i=1;i<=n;i++)a[i]=b[i]=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1')a[i]=1;
    }
    build1();
    for(int i=1;i<=n;i++){
        if(a[i]==1)continue;
        if(i==1||i==n)continue;
        if(tt[i-1]=='1'&&tt[i+1]=='1')b[i]=1;
    }
    build2();
    int l,r;
    while(q--){
        cin>>l>>r;
        int ans=0;
        if(l==r){
            if(s[l]=='1')ans++;
            cout<<ans<<endl;
            continue;
        }else{
            ans+=query1(r)-query1(l-1);
            ans+=query2(l+2,r-2);
            int t1=l+1,t2=r-1;
            if(t1==t2){
                if(s[t1]=='0'&&t[t1+1]=='1'&&t[t1-1]=='1')ans++;
            }else{
                if(t1+1<=r){
                    if(s[t1]=='0'&&tt[t1+1]=='1'&&t[t1-1]=='1')ans++;
                }
                if(t2-1>=l){
                    if(s[t2]=='0'&&t[t2+1]=='1'&&tt[t2-1]=='1')ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
        // cout<<endl;
    }
    return 0;
}