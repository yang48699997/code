#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
int n,q;
const int N=4e5+5;
const int mod=998244353;
ll a[N],b[N],suma[N],sumb[N],la[N],lb[N],res[N],c[N];

void solve(){
    cin>>n>>q;
    int m=sqrt(n);
    if(m*m<n)m++;
    for(int i=1;i<=m*m;i++){
        a[i]=b[i]=0;
    }
    for(int i=0;i<m;i++){
        la[i]=lb[i]=res[i]=0;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=0;i<m;i++){
        ll tot=0;
        for(int j=1;j<=m;j++){
            c[i*m+j]=a[i*m+j]*b[i*m+j]%mod;
            suma[i]+=a[i*m+j];
            sumb[i]+=b[i*m+j];
            tot=(tot+c[i*m+j])%mod;
        }
        res[i]=tot;
    }
    ll l,r,x,t;
    while(q--){
        cin>>t>>l>>r;
        if(t==1){
            cin>>x;
            if((l-1)/m==(r-1)/m){
                for(int i=l;i<=r;i++){
                    a[i]=(a[i]+x)%mod;
                    suma[(l-1)/m]=(suma[(l-1)/m]+x)%mod;
                    res[(l-1)/m]=(res[(l-1)/m]+a[i]*b[i]-c[i])%mod;
                    if(res[(l-1)/m]<0)res[(l-1)/m]+=mod;
                    c[i]=a[i]*b[i]%mod;
                }
                continue;
            }
            ll bl=(l-1)/m+1;
            for(int i=l;i<=bl*m;i++){
                a[i]=(a[i]+x)%mod;
                ll cur=a[i]*b[i]%mod;
                res[bl-1]=(res[bl-1]+cur-c[i])%mod;
                suma[bl-1]=(suma[bl-1]+x)%mod;
                if(res[bl-1]<0)res[bl-1]+=mod;
                c[i]=cur;
            }
            ll br=(r-1)/m;
            for(int i=br*m+1;i<=r;i++){
                a[i]=(a[i]+x)%mod;
                ll cur=a[i]*b[i]%mod;
                res[br]=(res[br]+cur-c[i])%mod;
                suma[br]=(suma[br]+x)%mod;
                if(res[br]<0)res[br]+=mod;
                c[i]=cur;
            }
            for(int i=bl;i<br;i++){
                la[i]=(la[i]+x)%mod;
            }
        }else if(t==2){
            cin>>x;
            if((l-1)/m==(r-1)/m){
                for(int i=l;i<=r;i++){
                    b[i]=(b[i]+x)%mod;
                    sumb[(l-1)/m]=(sumb[(l-1)/m]+x)%mod;
                    res[(l-1)/m]=(res[(l-1)/m]+a[i]*b[i]-c[i])%mod;
                    if(res[(l-1)/m]<0)res[(l-1)/m]+=mod;
                    c[i]=a[i]*b[i]%mod;
                }
                continue;
            }
            
            ll bl=(l-1)/m+1;
            for(int i=l;i<=bl*m;i++){
                b[i]=(b[i]+x)%mod;
                ll cur=a[i]*b[i]%mod;
                res[bl-1]=(res[bl-1]+cur-c[i])%mod;
                if(res[bl-1]<0)res[bl-1]+=mod;
                c[i]=cur;
            }
            ll br=(r-1)/m;
            for(int i=br*m+1;i<=r;i++){
                b[i]=(b[i]+x)%mod;
                ll cur=a[i]*b[i]%mod;
                res[br]=(res[br]+cur-c[i])%mod;
                if(res[br]<0)res[br]+=mod;
                c[i]=cur;
            }
            for(int i=bl;i<br;i++){
                lb[i]=(lb[i]+x)%mod;
            }
        }else{
            ll ans=0;
            if((l-1)/m==(r-1)/m){
                for(int i=l;i<=r;i++){
                    ans=(ans+c[i])%mod;
                }
                cout<<ans<<endl;
                continue;
            }
            ll bl=(l-1)/m+1;
            for(int i=l;i<=bl*m;i++){
                ans=(ans+c[i])%mod;
            }
            ll br=(r-1)/m;
            for(int i=br*m+1;i<=r;i++){
                ans=(ans+c[i])%mod;
            }
            for(int i=bl;i<br;i++){
                ans=(ans+res[i])%mod;
                ans=(ans+suma[i]*lb[i]+sumb[i]*la[i]+l a[i]*lb[i]%mod*m)%mod;
            }
            cout<<ans<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}