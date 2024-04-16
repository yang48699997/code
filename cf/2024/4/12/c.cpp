/*
 * Author: Ram
 * Date: 2024-04-12
 * Source: https://codeforces.com/contest/1954/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int f[1000],d[1000],m;
void dif(int x){
    int y=sqrt(x);
    m=1;
    for(int i=1;i<=y;i++){
        f[i]=m++;
        d[i]=(x-1)/i+1;
    }
    f[m]=m;
    d[m]=(x-1)/m+1;
    m++;
    int j=m-1;
    for(int i=m;j>0;i++,j--){
        f[i]=d[j];
        d[i]=f[j];
    }
    cout<<x<<' '<<m<<endl;
    for(int i=1;i<m*2-1;i++)cout<<f[i]<<' '<<d[i]<<endl;
    cout<<endl;
}
void dif2(int x){
    int y=sqrt(x);
    m=1;
    for(int i=1;i<=y;i++){
        f[i]=m++;
        d[i]=x/i;
    }
    f[m]=m;
    d[m]=x/m;
    m++;
    int j=m-1;
    for(int i=m;j>0;i++,j--){
        f[i]=d[j];
        d[i]=f[j];
    }
    cout<<x<<' '<<m<<endl;
    for(int i=1;i<m*2-1;i++)cout<<f[i]<<' '<<d[i]<<endl;
    cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int mx=0,mi=1e9;
    for(int i=0;i<n;i++)cin>>a[i],mx=max(mx,a[i]),mi=min(mi,a[i]);
    vector<int> ans(mx+1);;
    vector<int> pre(n),suf(n);
    stack<int> s;
    s.push(mi);
    for(int i=0;i<n;i++){
        int x=a[i];
        while(!s.empty()&&s.top()>=x)s.pop();
        if(!s.empty())pre[i]=s.top();
        else pre[i]=x;
        s.push(x);
    }
    s=stack<int>();
    s.push(mi);
    for(int i=n-1;i>=0;i--){
        int x=a[i];
        while(!s.empty()&&s.top()>=x)s.pop();
        if(!s.empty())suf[i]=s.top();
        else suf[i]=x;
        s.push(x);
    }
    ans[1]=mi;
    for(int i=0;i<n;i++){
        a[i]-=max(pre[i],suf[i]);
        ans[1]+=a[i];
    }
    dif(mi);
    for(int j=2;j<m;j++){
            ans[f[j]]-=d[j-1]-d[j];
            // cout<<f[j]<<' '<<d[j]<<endl;
        }
    for(int i=0;i<n;i++){
        dif2(a[i]);
        
        for(int j=2;j<m;j++){
            ans[f[j]]-=d[j-1]-d[j];
            // cout<<f[j]<<' '<<d[j]<<endl;
        }
    }
    for(int i=1;i<=mx;i++){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}