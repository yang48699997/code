#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll res1=0,res2=0;
    for(int i=0;i<n;i++){
        res2=max(res2+a[i],abs(res1+a[i]));
        res1+=a[i];
        res2=abs(res2);
    }
    res1=abs(res1);
    cout<<max(res1,res2);
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