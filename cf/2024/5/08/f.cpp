/*
 * Author: Ram
 * Date: 2024-05-08
 * Source: https://codeforces.com/gym/105143/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

int n,k;
int res;
bool check(int x){
    int ans=0;
    int cur=n;
    for(int i=1;i<=n;i++){
        cout<<"? "<<i<<' '<<cur<<' '<<x<<endl;
        cin>>res;
        if(res==0){
            i--;
            cur--;
            if(cur==0)break;
        }else ans+=cur;
    }
    return ans<k;
}

void solve(){
    cin>>n>>k;
    k=n*n-k+1;
    int l=1,r=n*n;
    while(l<=r){
        int mid=(r-l)/2+l;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<"! "<<l<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}