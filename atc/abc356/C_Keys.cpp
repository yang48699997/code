#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)a[i]=i;
    vector<vector<int>> c(m,vector<int> (n,-1));
    vector<int> p(m),v(m);
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        p[i]=x;
        for(int j=0;j<x;j++)cin>>c[i][j],c[i][j]--;
        char res;
        cin>>res;
        if(res=='o')v[i]=1;
    }
    int ans=0;
    int pp=0;
    for(int cur=0;cur<1<<n;cur++){
        bool ok=true;
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<p[i];j++){
                if(cur>>c[i][j]&1)cnt++;
            }
            if((cnt>=k)!=v[i]){
                ok=false;
                break;
            }
        }
        if(ok)ans++;
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