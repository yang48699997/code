#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int l=0,r=0;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            if(a[i]==1)cnt1++;
            else if(a[i]==-1)cnt2++;
        }else{
            if(a[i]>b[i])l+=a[i];
            else r+=b[i];
        }
    }
    if(l<r)swap(l,r);
    while(l!=r&&(cnt1||cnt2)){
        if(cnt1){
            r++;
            cnt1--;
        }else if(cnt2){
            l--;
            cnt2--;
        }
    }
    int lef=cnt1-cnt2;
    if(lef>0){
        cout<<l+lef/2;
    }else if(lef<0){
        cout<<l+(lef-1)/2;
    }else cout<<min(l,r);
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