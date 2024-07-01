#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> e(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        e[x].push_back(i);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll cnt=n-i+1;
        ans+=cnt*(i/2);
    }
    for(auto &ed:e){
        if(ed.size()==0)continue;
        int cnt=ed.size();
        vector<int> ld(cnt),rd(cnt);
        for(int i=0;i<cnt;i++){
            ld[i]=ed[i]+1;
            rd[i]=n-ed[i];
        }
        int r=cnt-1;
        ll sum=0;
        for(int i=0;i<cnt-1;i++){
            while(r>i&&rd[r]<ld[i]){
                sum+=rd[r];
                r--;
            }
            ans-=sum;
            ans-=(ll)(r-i)*ld[i];
            if(r==i){
                sum-=rd[r+1];
                r++;
            }
        }
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