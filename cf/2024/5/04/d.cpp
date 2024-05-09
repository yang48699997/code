/*
 * Author: Ram
 * Date: 2024-05-04
 * Source: https://atcoder.jp/contests/abc352/tasks/abc352_d
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> p(n+1),nums(n+1);
    for(int i=1;i<=n;i++)cin>>p[i],nums[p[i]]=i;
    set<int> st;
    for(int i=1;i<=k;i++)st.insert(nums[i]);
    int ans=*st.rbegin()-*st.begin();
    for(int i=k+1;i<=n;i++){
        st.insert(nums[i]);
        st.erase(nums[i-k]);
        ans=min(ans,*st.rbegin()-*st.begin());
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