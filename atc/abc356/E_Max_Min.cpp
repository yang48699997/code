#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e6+5;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    vector<int> cnt(N);
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        cnt[x]++;
    }
    ll ans=0;
    for(int i=1;i<N;i++)cnt[i]+=cnt[i-1];
    for(int i=1;i<N;i++){
        // cerr<<cnt[i]<<" ";
        ll cur=cnt[i]-cnt[i-1];
        if(cur==0)continue;
        ll res=1;
        ans+=cur*(cur-1)/2;
        for(int j=i+i;j<N;j+=i){
            if(j!=i+i)ans+=res*(cnt[j-1]-cnt[j-i-1])*cur;
            else ans+=res*(cnt[j-1]-cnt[j-i])*cur;
            res++;
            // if(j+i>=N)ans+=res*(cnt[N-1]-cnt[j-1])*cur;
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