/*
 * Author: Ram
 * Date: 2024-05-15
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==a.back())cnt++;
    }
    if(cnt%2==1)cout<<"Alice";
    else cout<<"Bob";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}