#include <bits/stdc++.h>
using namespace std;

int f(int l){
    int cur=0;
    int ans=0,x;
    while(cur<=l){
        int cnt=0;
        for(int i=0;i<31;i++){
            if(cur+(1<<i)-1<=l)cnt=i;
            else break;
        }
        cout<<"? "<<cnt<<' '<<(l>>cnt>>1<<1)<<endl;
        cin>>x;
        ans=(ans+x)%100;
        cur+=1<<cnt;
    }
    return ans;
}

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    int ans=0,x;
    if(l!=0)ans=f(l-1);
    x=f(r);
    ans=(x-ans+100)%100;

    cout<<"! "<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}