/*
 * Author: Ram
 * Date: 2024-05-18
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
int T;
void solve(){
    int n,ha,hb;
    cin>>n>>ha>>hb;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int cnt1=0,ok=false;
    for(int i=n-1;i>=0;i--){
        if(a[i]==-1)break;
        hb-=a[i];
        cnt1++;
        if(hb<=0){
            ok=true;
            break;
        }
    }
    int cnt2=0;
    for(int i=0;i<n;i++){
        if(b[i]==-1)continue;
        ha-=b[i];
        if(ha>0)cnt2++;
        else break;
    }
    if(cnt1<=cnt2&&ok)cout<<"yes";
    else cout<<"no";
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