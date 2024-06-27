#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int T;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+m+1),b(n+m+1);
    for(int i=0;i<n+m+1;i++)cin>>a[i];
    for(int i=0;i<n+m+1;i++)cin>>b[i];
    vector<vector<int>> pre(n+m+1,vector<int> (2));
    vector<ll> res(n+m+1);
    vector<ll> suf0(n+m+2);
    vector<ll> suf1(n+m+2);
    suf0[n+m]=a[n+m];
    suf1[n+m]=b[n+m];
    for(int i=n+m-1;i>=0;i--)suf0[i]=suf0[i+1]+a[i];
    for(int i=n+m-1;i>=0;i--)suf1[i]=suf1[i+1]+b[i];
    vector<ll> c(n+m+1);
    vector<ll> cc(n+m+1);
    vector<int> c1,c2;
    vector<ll> res1,res2;
    for(int i=0;i<n+m+1;i++){
        if(a[i]>b[i])cc[i]=0;
        else cc[i]=1;
        if(cc[i])c2.push_back(i),res2.push_back(b[i]-a[i]);
        else c1.push_back(i),res1.push_back(a[i]-b[i]);
    }
    for(int i=1;i<res1.size();i++)res1[i]+=res1[i-1];
    for(int i=1;i<res2.size();i++)res2[i]+=res2[i-1];
    for(int i=1;i<=n+m;i++){
        pre[i][0]=pre[i-1][0];
        pre[i][1]=pre[i-1][1];
        res[i]=res[i-1];
        if(pre[i][0]==n){
            pre[i][1]++;
            res[i]+=b[i-1];
            c[i-1]=1;
        }else if(pre[i][1]==m){
            pre[i][0]++;
            res[i]+=a[i-1];
            c[i-1]=0;
        }else{
            if(a[i-1]>b[i-1]){
                pre[i][0]++;
                res[i]+=a[i-1];
                c[i-1]=0;
            }else{
                pre[i][1]++;
                res[i]+=b[i-1];
                c[i-1]=1;
            }
        }
    }
    for(int i=0;i<n+m;i++){
        ll cur=res[i];
        int l0=n-pre[i][0];
        int l1=m-pre[i][1];
        auto it=upper_bound(c1.begin(),c1.end(),i);
        int cnt=it-c1.begin();
        // cout<<i<<":"<<endl;
        // cout<<l0<<' '<<l1<<' '<<cnt<<endl;
        if(l0==0){
            cur+=suf1[i+1];
        }else if(l1==0){
            cur+=suf0[i+1];
            // cout<<"**"<<suf0[i+2]<<endl;
        }else if(it!=c1.end()&&cnt+l0-1<c1.size()){
            cur+=suf1[i+1];
            cur+=res1[cnt+l0-1];
            if(cnt>0)cur-=res1[cnt-1];
        }else{
            auto itt=upper_bound(c2.begin(),c2.end(),i);
            cnt=itt-c2.begin();
            cur+=suf0[i+1];
            cur+=res2[cnt+l1-1];
            if(cnt>0)cur-=res2[cnt-1];
        }
        cout<<cur<<" ";
    }
    cout<<res[n+m];
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