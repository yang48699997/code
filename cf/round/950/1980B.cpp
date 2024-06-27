#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,f,k;
    cin>>n>>f>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int cur=a[f-1];
    sort(a.rbegin(),a.rend());
    if(cur==a[k-1]){
        if(k<n&&a[k]==a[k-1])cout<<"MAYBE";
        else cout<<"YES";
    }else if(cur<a[k-1])cout<<"NO";
    else cout<<"YES";
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